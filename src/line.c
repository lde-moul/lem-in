/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:54:45 by lde-moul          #+#    #+#             */
/*   Updated: 2017/08/28 18:54:21 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anthill.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

int		add_line(t_line **lines, char **text)
{
	int		n;
	t_line	*line;

	if ((n = get_next_line(0, text)) != 1)
		return (n);
	if (!(line = (t_line*)malloc(sizeof(t_line))))
	{
		free(*text);
		return (-1);
	}
	line->text = *text;
	line->next = *lines;
	*lines = line;
	return (1);
}

void	reverse_lines(t_line **lines)
{
	t_line *line;
	t_line *next;
	t_line *prev;

	line = *lines;
	prev = NULL;
	while (line)
	{
		next = line->next;
		line->next = prev;
		prev = line;
		line = next;
	}
	*lines = prev;
}

void	display_lines(t_line *lines)
{
	t_line	*line;

	line = lines;
	while (line)
	{
		ft_putstr(line->text);
		ft_putchar('\n');
		line = line->next;
	}
	ft_putchar('\n');
}
