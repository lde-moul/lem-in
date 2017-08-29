/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:47:44 by lde-moul          #+#    #+#             */
/*   Updated: 2017/08/28 19:02:15 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "distances.h"
#include <stdlib.h>

static void		init_distances(t_anthill *anthill)
{
	int		i;

	i = 0;
	while (i < anthill->room_number)
	{
		anthill->rooms[i].distance = INFINITY;
		anthill->rooms[i].visited = 0;
		i++;
	}
	anthill->rooms[anthill->end].distance = 0;
}

static t_room	*get_nearest_room(t_anthill *anthill)
{
	t_room			*room;
	unsigned int	dist;
	int				i;

	room = NULL;
	dist = INFINITY;
	i = 0;
	while (i < anthill->room_number)
	{
		if (!anthill->rooms[i].visited && anthill->rooms[i].distance < dist)
		{
			room = &anthill->rooms[i];
			dist = room->distance;
		}
		i++;
	}
	return (room);
}

static void		update_distances(t_room *room)
{
	int	i;

	room->visited = 1;
	i = 0;
	while (i < room->tube_number)
	{
		if (room->distance + 1 < room->tubes[i]->distance)
			room->tubes[i]->distance = room->distance + 1;
		i++;
	}
}

void			find_distances(t_anthill *anthill)
{
	t_room	*room;

	init_distances(anthill);
	while ((room = get_nearest_room(anthill)))
		update_distances(room);
}
