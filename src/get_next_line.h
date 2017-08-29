/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:01:06 by lde-moul          #+#    #+#             */
/*   Updated: 2016/12/07 19:33:52 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

typedef struct	s_buf
{
	int		fd;
	char	content[BUFF_SIZE];
	int		pos;
	int		size;
}				t_buf;

int				get_next_line(const int fd, char **line);

#endif
