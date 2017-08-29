/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_by_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:06:57 by lde-moul          #+#    #+#             */
/*   Updated: 2017/08/28 19:09:41 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anthill.h"
#include "libft.h"

int	get_room_by_name(char *name, t_anthill *anthill)
{
	int	i;

	i = 0;
	while (i < anthill->room_number && ft_strcmp(name, anthill->rooms[i].name))
		i++;
	return (i < anthill->room_number ? i : -1);
}
