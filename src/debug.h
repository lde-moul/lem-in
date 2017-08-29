/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:34:51 by lde-moul          #+#    #+#             */
/*   Updated: 2017/01/09 17:02:14 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <stdio.h>

# define PRINT(format, args...) printf("%s, %s, line %d: " format "\n", __FILE__, __FUNCTION__, __LINE__ , ##args);
# define WORKS printf("%s, %s, line %d\n", __FILE__, __FUNCTION__, __LINE__);
# define ASSERT(t) if (!(t)) PRINT("ERROR: " #t)
# define ASSERT_PTR(t) if (!(t)) PRINT("ERROR: " #t " is NULL")

# define PRINT_LST(l) PRINT("%s = %p (content = %p, size = %zd)", #l, l, l->content, l->content_size)
# define ASSERT_LST(l) if (!assert_lst(l)) PRINT("Error: " #l " has a NULL content")

#endif
