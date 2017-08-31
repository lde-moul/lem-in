/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:03:04 by lde-moul          #+#    #+#             */
/*   Updated: 2017/08/31 18:05:59 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	free_and_return(void *p, t_list **list, int n)
{
	if (p)
		free(p);
	ft_lstdel(list, NULL);
	return (n);
}

static char	*concat_line(t_list **list)
{
	char	*line;
	t_list	*elem;
	size_t	n;

	ft_lstrev(list);
	n = 1;
	elem = *list;
	while (elem)
	{
		n += elem->content_size;
		elem = elem->next;
	}
	if (!(line = (char*)malloc(n * sizeof(char))))
		return (NULL);
	n = 0;
	elem = *list;
	while (elem)
	{
		ft_memcpy(line + n, elem->content, elem->content_size);
		n += elem->content_size;
		elem = elem->next;
	}
	line[n] = '\0';
	return (line);
}

static int	read_buffer(t_buf *b, char **line, t_list *list)
{
	int n;

	if (b->size)
		n = 0;
	else if ((n = read(b->fd, b->content, BUFF_SIZE)) == -1)
		return (-1);
	b->size += n;
	if (!b->size)
	{
		if (!(*line = concat_line(&list)))
			return (-1);
		return (list ? 1 : 0);
	}
	return (2);
}

static int	read_line(t_buf *b, char **line)
{
	t_list			*list;
	t_list			*elem;
	char			*c;
	int				n;

	list = NULL;
	while (1)
	{
		if ((n = read_buffer(b, line, list)) != 2)
			return (free_and_return(NULL, &list, n));
		c = ft_memchr(b->content, '\n', b->size);
		if (!(elem = ft_lstnew(b->content, c ? c - b->content : b->size)))
			return (free_and_return(NULL, &list, -1));
		ft_lstadd(&list, elem);
		b->size = c ? b->size - (c + 1 - b->content) : 0;
		if (c)
		{
			if (!(*line = concat_line(&list)))
				return (free_and_return(NULL, &list, -1));
			ft_memmove(b->content, c + 1, b->size);
			return (free_and_return(NULL, &list, 1));
		}
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*elem;
	t_buf			*buf;
	int				n;

	if (fd < 0 || !line)
		return (-1);
	elem = list;
	while (elem && fd != ((t_buf*)elem->content)->fd)
		elem = elem->next;
	if (!elem)
	{
		if (!(buf = ft_memalloc(sizeof(t_buf))))
			return (-1);
		buf->fd = fd;
		if (!(elem = ft_lstnew(NULL, 0)))
			return (free_and_return(buf, NULL, -1));
		elem->content = buf;
		elem->content_size = sizeof(t_buf);
		ft_lstadd(&list, elem);
	}
	if ((n = read_line((t_buf*)elem->content, line)) != 1)
		ft_lstdelfrom(&list, &elem, NULL);
	return (n);
}
