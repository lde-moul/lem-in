/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 18:06:02 by lde-moul          #+#    #+#             */
/*   Updated: 2017/07/24 18:58:36 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "anthill.h"

int		add_line(t_line **lines, char **text);
void	reverse_lines(t_line **lines);
void	display_lines(t_line *lines);

#endif
