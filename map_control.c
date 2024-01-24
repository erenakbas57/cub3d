/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:01:46 by makbas            #+#    #+#             */
/*   Updated: 2024/01/14 16:15:20 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	element_c(t_window *map)
{
	int	y;
	int	x;
	int	loc;

	y = 0;
	loc = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x] != '\n' && map->map[y][x] != '\0')
		{
			if (ft_strchr("01", map->map[y][x]))
				x++;
			else if (ft_strchr("NSEW", map->map[y][x]))
			{
				map->player_dir = map->map[y][x];
				map->player_loc[0] = y;
				map->player_loc[1] = x;
				loc++;
				x++;
			}
			else
				return (1);
		}
		y++;
	}
	if (loc != 1)
		return (1);
	return (0);
}

int	valid_c(t_window *map)
{
	char	**map_line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (map->map[i])
		i++;
	map_line = (char **)malloc(sizeof(char *) * (i + 1));
	while (map->map[j])
	{
		map_line[j] = ft_strdup(map->map[j]);
		j++;
	}
	map_line[j] = NULL;
	recursive_p(map, map_line, map->player_loc[0], map->player_loc[1]);
	free_array(map_line);
	return (0);
}

void	recursive_p(t_window *map, char **map_l, int y, int x)
{
	if (((int)ft_strlen(map_l[y + 1]) <= x) || ((int)ft_strlen(map_l[y - 1]) <= x) || (x - 1 < 0) || ((int)ft_strlen(map_l[y]) < x + 2))
	{
		printf("line : %s\n", map_l[y]);
		free_array(map_l);
		error("Error : Map is not closed", map);
	}
	else
	{
		if (map_l[y][x + 1] == '0')
		{
			map_l[y][x + 1] = 'P';
			recursive_p(map, map_l, y, x + 1);
		}
		if (map_l[y][x - 1] == '0')
		{
			map_l[y][x - 1] = 'P';
			recursive_p(map, map_l, y, x - 1);
		}
		if (map_l[y + 1][x] == '0')
		{
			map_l[y + 1][x] = 'P';
			recursive_p(map, map_l, y + 1, x);
		}
		if (map_l[y - 1][x] == '0')
		{
			map_l[y - 1][x] = 'P';
			recursive_p(map, map_l, y - 1, x);
		}
	}
}
