/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:33:47 by lde-moul          #+#    #+#             */
/*   Updated: 2017/08/29 18:41:56 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "line.h"
#include "libft.h"
#include <stdlib.h>

static int	realloc_tubes(t_anthill *anthill)
{
	t_tube	*tubes;

	if (anthill->tube_number + 1 > anthill->allocated)
	{
		anthill->allocated *= 2;
		tubes = (t_tube*)malloc(anthill->allocated * sizeof(t_tube));
		if (!tubes)
			return (0);
		ft_memcpy(tubes, anthill->tubes, anthill->tube_number * sizeof(t_tube));
		free(anthill->tubes);
		anthill->tubes = tubes;
	}
	anthill->tube_number++;
	return (1);
}

static int	add_tube(t_room *room, t_room *tube)
{
	t_room	**tubes;

	tubes = (t_room**)malloc((room->tube_number + 1) * sizeof(t_room*));
	if (!tubes)
		return (0);
	ft_memcpy(tubes, room->tubes, room->tube_number * sizeof(t_room*));
	tubes[room->tube_number] = tube;
	free(room->tubes);
	room->tubes = tubes;
	room->tube_number++;
	return (1);
}

static int	get_tube(t_anthill *anthill, char *line)
{
	int	i;
	int	n1;
	int	n2;

	i = 0;
	while (line[i] != '-')
		i++;
	line[i] = '\0';
	if ((n1 = get_room_by_name(line, anthill)) == -1)
		return (0);
	line[i] = '-';
	if ((n2 = get_room_by_name(line + i + 1, anthill)) == -1)
		return (0);
	if (n1 == n2)
		return (1);
	i = 0;
	while (i < anthill->rooms[n1].tube_number)
		if (anthill->rooms[n1].tubes[i++] == &anthill->rooms[n2])
			return (1);
	anthill->tubes[anthill->tube_number - 1].room1 = n1;
	anthill->tubes[anthill->tube_number - 1].room2 = n2;
	if (!(add_tube(&anthill->rooms[n1], &anthill->rooms[n2])
	&& add_tube(&anthill->rooms[n2], &anthill->rooms[n1])))
		return (-1);
	return (1);
}

static int	line_is_tube(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'L')
		return (0);
	while (line[i] && line[i] != '-' && line[i] != ' ')
		i++;
	if (line[i] != '-')
		return (0);
	i++;
	if (line[i] == 'L')
		return (0);
	while (line[i] && line[i] != '-' && line[i] != ' ')
		i++;
	return (!line[i]);
}

int			get_tubes(t_anthill *anthill, char *line)
{
	int	n;

	anthill->tube_number = 0;
	anthill->allocated = 16;
	if (!(anthill->tubes = (t_tube*)malloc(16 * sizeof(t_tube))))
		return (0);
	n = 1;
	while (n)
	{
		if (line[0] != '#')
		{
			if (!line_is_tube(line))
				return (1);
			if (!realloc_tubes(anthill))
				return (0);
			if ((n = get_tube(anthill, line)) != 1)
				return (0);
		}
		if ((n = add_line(&anthill->lines, &line)) == -1)
			return (0);
	}
	return (1);
}
