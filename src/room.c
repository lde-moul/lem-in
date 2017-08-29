/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 17:51:27 by lde-moul          #+#    #+#             */
/*   Updated: 2017/08/28 19:05:56 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "line.h"
#include "libft.h"
#include <stdlib.h>

static int	get_room(t_anthill *anthill, char *line)
{
	t_room	*room;
	int		i;

	room = &anthill->rooms[anthill->room_number - 1];
	i = 0;
	while (line[i] != ' ')
		i++;
	room->name = (char*)malloc((i + 1) * sizeof(char));
	if (!room->name)
		return (0);
	ft_strncpy(room->name, line, i);
	i++;
	room->x = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i++;
	room->y = ft_atoi(&line[i]);
	room->tube_number = 0;
	room->ants = 0;
	if (anthill->command == 1)
		anthill->start = anthill->room_number - 1;
	else if (anthill->command == 2)
		anthill->end = anthill->room_number - 1;
	anthill->command = 0;
	return (1);
}

static int	realloc_rooms(t_anthill *anthill)
{
	t_room	*rooms;

	if (anthill->room_number + 1 > anthill->allocated)
	{
		anthill->allocated *= 2;
		rooms = (t_room*)malloc(anthill->allocated * sizeof(t_room));
		if (!rooms)
			return (0);
		ft_memcpy(rooms, anthill->rooms, anthill->room_number * sizeof(t_room));
		free(anthill->rooms);
		anthill->rooms = rooms;
	}
	anthill->rooms[anthill->room_number].name = NULL;
	anthill->rooms[anthill->room_number].tubes = NULL;
	anthill->room_number++;
	return (1);
}

static int	check_coordinate(char *s, int *i)
{
	if (s[*i] == '-')
		(*i)++;
	if (!s[*i])
		return (0);
	while (ft_isdigit(s[*i]))
		(*i)++;
	return (!s[*i] || s[*i] == ' ');
}

static int	line_is_room(char *line)
{
	int	i;

	if (line[0] == ' ' || line[0] == 'L')
		return (0);
	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '-')
		i++;
	if (line[i] != ' ')
		return (0);
	i++;
	if (!(check_coordinate(line, &i) && line[i]))
		return (0);
	i++;
	return (check_coordinate(line, &i) && !line[i]);
}

char		*get_rooms(t_anthill *anthill)
{
	char	*line;

	anthill->allocated = 16;
	if (!(anthill->rooms = (t_room*)malloc(16 * sizeof(t_room))))
		return (NULL);
	while (1)
	{
		if ((add_line(&anthill->lines, &line)) != 1)
			return (0);
		if (line[0] != '#')
		{
			if (!line_is_room(line))
				break ;
			if (!realloc_rooms(anthill))
				return (NULL);
			if (!get_room(anthill, line))
				return (NULL);
		}
		else if (!ft_strcmp(line, "##start"))
			anthill->command = 1;
		else if (!ft_strcmp(line, "##end"))
			anthill->command = 2;
	}
	return (anthill->start != -1 && anthill->end != -1 ? line : NULL);
}
