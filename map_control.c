/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:55:24 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 17:26:53 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rectangle_c(t_map *map)
{
	int	y;
	int	x;
	int	len;

	len = ft_strlen(map->map_line[0]);
	y = 0;
	while (y < map->map_y_line)
	{
		x = 0;
		while (map->map_line[y] && map->map_line[y][x] != '\n' && \
			x < (int)(ft_strlen(map->map_line[y])))
			x++;
		if (x != len -1)
		{
			ft_printf("HATA : %d. satırda dikdörtgen hatası!", y + 1);
			return (1);
		}
		y++;
	}
	return (0);
}
