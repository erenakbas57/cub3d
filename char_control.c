/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:26:02 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 17:37:15 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_control(t_map *map, int x, int y)
{
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x])
		{
			if (map->map_line[y][x] == 'E')
				map->e_count++;
			if (map->map_line[y][x] == 'C')
				map->c_count++;
			if (map->map_line[y][x] == 'P')
			{
				map->p_y_loc = y;
				map->p_x_loc = x;
				map->p_count++;
			}
			x++;
		}
		y++;
	}
}

int	char_c(t_map *map)
{
	char_control(map, 0, 0);
	if (map->e_count != 1)
	{
		ft_printf("HATA : ÇIKIŞ sayısı 1 değil!");
		return (1);
	}
	if (map->p_count != 1)
	{
		ft_printf("HATA : OYUNCU sayısı 1 değil!");
		return (1);
	}
	if (map->c_count == 0)
	{
		ft_printf("HATA : TOPLANABİLİR sayısı 0!");
		return (1);
	}
	return (0);
}

int	element_c(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] != '\n' && map->map_line[y][x] != '\0')
		{
			if (ft_strchr(MAP_CHAR, map->map_line[y][x]))
				x++;
			else
			{
				ft_printf("HATA : %d. satırda '%c' harfi var!", y, \
					map->map_line[y][x]);
				return (1);
			}
		}
		y++;
	}
	return (0);
}
