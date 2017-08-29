/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:29:39 by lde-moul          #+#    #+#             */
/*   Updated: 2017/07/24 18:32:20 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTHILL_H
# define ANTHILL_H

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				tube_number;
	struct s_room	**tubes;
	unsigned int	distance;
	int				ants;
	char			visited;
}				t_room;

typedef struct	s_tube
{
	int	room1;
	int	room2;
}				t_tube;

typedef struct	s_line
{
	char			*text;
	struct s_line	*next;
}				t_line;

typedef struct	s_anthill
{
	int		ant_number;
	int		*ants;
	int		start;
	int		end;
	int		room_number;
	t_room	*rooms;
	int		tube_number;
	t_tube	*tubes;
	t_line	*lines;
	int		command;
	int		allocated;
}				t_anthill;

#endif
