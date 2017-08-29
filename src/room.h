/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 17:52:19 by lde-moul          #+#    #+#             */
/*   Updated: 2017/07/11 16:36:03 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include "anthill.h"

int		get_room_by_name(char *name, t_anthill *anthill);
char	*get_rooms(t_anthill *anthill);

#endif
