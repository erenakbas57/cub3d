/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:44:12 by makbas            #+#    #+#             */
/*   Updated: 2024/01/29 18:44:50 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	intro(t_data *data)
{
	data->keys = NULL;
	data->player = NULL;
	data->wall = NULL;
	data->screen = NULL;

	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = NULL;
	data->c = NULL;

	data->file_line = NULL;
	data->map_line = NULL;
}

void	control(int ac, char *av, t_data *data)
{
	if (ac != 2)
		error("Error : Wrong number of arguments", data);
	if (ft_strncmp(av + ft_strlen(av) - 4, ".cub", 4))
		error("Error : Wrong file format", data);
	if (file_read(data, av))
		error("\0", data);
	if (dir_control(data))
		error("Error : Wrong wall file or color", data);
	map_read(data);
	if (element_c(data) || valid_c(data))
		error("Error: Wrong map", data);
}

// void start(t_data *data)
// {

// 

int	close_window(t_data *cub3d)
{
    mlx_destroy_window(cub3d->screen->mlx, cub3d->screen->mlx_win);
	system("leaks cub3d");
	exit(0);
}

int	key_press(int keycode, t_data *cub3d)
{
	if (keycode == 53)
	{
		free_directory(cub3d);
		exit(0);
	}
	if (keycode == 13)
		cub3d->keys->w = 1;
	if (keycode == 0)
		cub3d->keys->a = 1;
	if (keycode == 1)
		cub3d->keys->s = 1;
	if (keycode == 2)
		cub3d->keys->d = 1;
	if (keycode == 123)
		cub3d->keys->left = 1;
	if (keycode == 124)
		cub3d->keys->right = 1;
	return (0);
}

int	key_release(int keycode, t_data *cub3d)
{
	if (keycode == 13)
		cub3d->keys->w = 0;
	if (keycode == 0)
		cub3d->keys->a = 0;
	if (keycode == 1)
		cub3d->keys->s = 0;
	if (keycode == 2)
		cub3d->keys->d = 0;
	if (keycode == 123)
		cub3d->keys->left = 0;
	if (keycode == 124)
		cub3d->keys->right = 0;
	return (0);
}
int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	intro(data);
	control(ac, av[1], data);
	init(data);

	mlx_loop_hook(data->screen->mlx, &render, data);
	mlx_hook(data->screen->mlx_win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->screen->mlx_win, 3, 1L << 1, &key_release, data);
	mlx_hook(data->screen->mlx_win, 17, 1L << 17, &close_window, data);
	mlx_loop(data->screen->mlx);

	free_file(data);
	free_map(data);
	free_directory(data);
	system("leaks cub3d");
	return (0);
}
