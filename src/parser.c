/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:26:27 by lde-moul          #+#    #+#             */
/*   Updated: 2017/08/28 18:55:56 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "tube.h"
#include "line.h"
#include "libft.h"
#include <stdlib.h>

static int	get_ant_number(t_anthill *anthill)
{
	char	*line;
	int		i;

	if ((add_line(&anthill->lines, &line)) != 1)
		return (0);
	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
		return (0);
	anthill->ant_number = ft_atoi(line);
	return (1);
}

int			get_anthill(t_anthill *anthill)
{
	char	*line;

	anthill->lines = NULL;
	anthill->start = -1;
	anthill->end = -1;
	anthill->command = 0;
	if (!get_ant_number(anthill))
		return (0);
	if (!(line = get_rooms(anthill)))
		return (0);
	if (!get_tubes(anthill, line))
		return (0);
	reverse_lines(&anthill->lines);
	return (1);
}
