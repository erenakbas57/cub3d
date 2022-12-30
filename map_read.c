/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:59:32 by makbas            #+#    #+#             */
/*   Updated: 2022/12/27 18:00:51 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_read_c(t_map *map, char *f_name)
{
	int	fd;
	int	i;

	map_read(map, f_name);
	if (!(map->map_line) || map->map_y_line <= 0)
	{
		map->map_line = NULL;
		return (1);
	}
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		free(map->map_line);
		return (1);
	}
	i = 0;
	map->map_line[i] = get_next_line(fd);
	while (map->map_line[i])
	{
		i++;
		map->map_line[i] = get_next_line(fd);
	}
	close(fd);
	return (0);
}

void	map_read(t_map *map, char *f_name)
{
	int		len;
	int		fd;
	char	c;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
	{
		map->map_y_line = 0;
		return ;
	}
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			len++;
	}
	len++;
	close(fd);
	map->map_line = malloc(sizeof(char *) * len + 1);
	if (!map->map_line)
		return ;
	map->map_line[len + 1] = NULL;
	map->map_y_line = len;
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_y_line)
	{
		free(map->map_line[i]);
		i++;
	}
	free(map->map_line);
}

int	ft_exit(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img_b);
	mlx_destroy_image(map->mlx, map->img_w);
	mlx_destroy_image(map->mlx, map->img_e);
	mlx_destroy_image(map->mlx, map->img_p);
	mlx_destroy_image(map->mlx, map->img_c);
	mlx_clear_window(map->mlx, map->mlx_win);
	free_map(map);
	exit(0);
	return (0);
}
