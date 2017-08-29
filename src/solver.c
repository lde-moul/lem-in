/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:29:04 by lde-moul          #+#    #+#             */
/*   Updated: 2017/08/28 19:01:50 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "distances.h"
#include "line.h"
#include "libft.h"
#include <stdlib.h>

static void		init_ants(t_anthill *anthill)
{
	int i;

	i = 0;
	while (i < anthill->ant_number)
	{
		anthill->ants[i] = anthill->start;
		i++;
	}
	anthill->rooms[anthill->start].ants = anthill->ant_number;
}

static t_room	*get_best_tube(t_anthill *anthill, t_room *room)
{
	t_room			*tube;
	unsigned int	best_dist;
	unsigned int	dist;
	int				i;

	if (room - anthill->rooms == anthill->end)
		return (NULL);
	tube = NULL;
	best_dist = INFINITY;
	i = 0;
	while (i < room->tube_number)
	{
		if (room->tubes[i] - anthill->rooms == anthill->end)
			return (room->tubes[i]);
		dist = room->tubes[i]->distance + room->tubes[i]->ants + room->ants;
		if (dist < best_dist)
		{
			tube = room->tubes[i];
			best_dist = dist;
		}
		i++;
	}
	return (tube->ants ? NULL : tube);
}

static void		move_ant(int ant, t_room *tube, int *first, t_anthill *anthill)
{
	if (*first)
		*first = 0;
	else
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(tube->name);
	anthill->rooms[anthill->ants[ant]].ants--;
	anthill->ants[ant] = tube - anthill->rooms;
	tube->ants++;
}

int				get_moves(t_anthill *anthill)
{
	int		i;
	t_room	*tube;
	int		first_move;

	find_distances(anthill);
	if (anthill->rooms[anthill->start].distance == INFINITY)
		return (0);
	if (!(anthill->ants = (int*)malloc(anthill->ant_number * sizeof(int))))
		return (0);
	init_ants(anthill);
	display_lines(anthill->lines);
	while (anthill->rooms[anthill->end].ants != anthill->ant_number)
	{
		first_move = 1;
		i = 0;
		while (i < anthill->ant_number)
		{
			tube = get_best_tube(anthill, &anthill->rooms[anthill->ants[i]]);
			if (tube)
				move_ant(i, tube, &first_move, anthill);
			i++;
		}
		ft_putchar('\n');
	}
	return (1);
}
