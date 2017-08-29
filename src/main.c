/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:59:59 by lde-moul          #+#    #+#             */
/*   Updated: 2017/08/28 18:49:44 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "parser.h"
#include "libft.h"
#include <stdlib.h>

static void	free_all(t_anthill *anthill)
{
	t_line	*next;
	int		i;

	while (anthill->lines)
	{
		next = anthill->lines->next;
		free(anthill->lines->text);
		free(anthill->lines);
		anthill->lines = next;
	}
	i = 0;
	while (i < anthill->room_number)
	{
		if (anthill->rooms[i].name)
			free(anthill->rooms[i].name);
		if (anthill->rooms[i].tubes)
			free(anthill->rooms[i].tubes);
		i++;
	}
	if (anthill->rooms)
		free(anthill->rooms);
	if (anthill->tubes)
		free(anthill->tubes);
	if (anthill->ants)
		free(anthill->ants);
}

int			main(void)
{
	t_anthill	anthill;

	anthill.room_number = 0;
	anthill.rooms = NULL;
	anthill.tubes = NULL;
	anthill.ants = NULL;
	if (!get_anthill(&anthill))
	{
		free_all(&anthill);
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	if (!get_moves(&anthill))
	{
		free_all(&anthill);
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	free_all(&anthill);
	return (0);
}
