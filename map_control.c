/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:01:46 by makbas            #+#    #+#             */
/*   Updated: 2024/01/17 18:03:10 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	element_c(t_data *data)
{
	int	y;
	int	x;
	int	loc;

	y = 0;
	loc = 0;
	while (data->map_line[y])
	{
		x = 0;
		while (data->map_line[y][x] != '\n' && data->map_line[y][x] != '\0')
		{
			if (ft_strchr("01", data->map_line[y][x]))
				x++;
			else if (ft_strchr("NSEW", data->map_line[y][x]))
			{
				data->player_dir = data->map_line[y][x];
				data->player_loc[0] = y;
				data->player_loc[1] = x;
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

int	valid_c(t_data *data)
{
	char	**map_line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (data->map_line[i])
		i++;
	map_line = (char **)malloc(sizeof(char *) * (i + 1));
	while (data->map_line[j])
	{
		map_line[j] = ft_strdup(data->map_line[j]);
		j++;
	}
	map_line[j] = NULL;
	recursive_p(data, map_line, data->player_loc[0], data->player_loc[1]);
	free_array(map_line);
	return (0);
}

void	recursive_p(t_data *data, char **map_l, int y, int x)
{
	if (((int)ft_strlen(map_l[y + 1]) <= x) || ((int)ft_strlen(map_l[y - 1]) <= x) || (x - 1 < 0) || ((int)ft_strlen(map_l[y]) < x + 2))
	{
		printf("line : %s\n", map_l[y]);
		free_array(map_l);
		error("Error : Map is not closed", data);
	}
	else
	{
		if (map_l[y][x + 1] == '0')
		{
			map_l[y][x + 1] = 'P';
			recursive_p(data, map_l, y, x + 1);
		}
		if (map_l[y][x - 1] == '0')
		{
			map_l[y][x - 1] = 'P';
			recursive_p(data, map_l, y, x - 1);
		}
		if (map_l[y + 1][x] == '0')
		{
			map_l[y + 1][x] = 'P';
			recursive_p(data, map_l, y + 1, x);
		}
		if (map_l[y - 1][x] == '0')
		{
			map_l[y - 1][x] = 'P';
			recursive_p(data, map_l, y - 1, x);
		}
	}
}
