/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:00:53 by makbas            #+#    #+#             */
/*   Updated: 2024/01/29 18:53:29 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init(t_data *data)
{
    data->keys = (t_keys *)malloc(sizeof(t_keys));
    keys_init(data);
    data->player = (t_player *)malloc(sizeof(t_player));
    player_init(data);


    data->screen = (t_screen *)malloc(sizeof(t_screen));
    data->screen->width = WIN_WIDTH;
    data->screen->height = WIN_HEIGHT;
    data->screen->mlx = mlx_init();
    data->screen->mlx_win = mlx_new_window(data->screen->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
    data->screen->img = mlx_new_image(data->screen->mlx, WIN_WIDTH, WIN_HEIGHT);
    data->screen->addr = (int *)mlx_get_data_addr(data->screen->img, &data->screen->bpp, &data->screen->size_line, &data->screen->endian);
    data->wall = (t_image *)malloc(sizeof(t_image) * 4);
    
    wall_init(data);
    data->screen->floor = (data->f[0] << 16) + (data->f[1] << 8) + (data->f[2]);
    data->screen->ceiling = (data->c[0] << 16) + (data->c[1] << 8) + (data->c[2]);
    data->ray = (t_raycaster *)malloc(sizeof(t_raycaster));
}

void keys_init(t_data *data)
{
    data->keys->w = 0;
    data->keys->a = 0;
    data->keys->s = 0;
    data->keys->d = 0;
    data->keys->right = 0;
    data->keys->left = 0;
}

void player_init(t_data *data)
{
    data->player->pos_x = data->player_loc[0] + 0.5;
    data->player->pos_y = data->player_loc[1] + 0.5;
	if (data->player_dir == 'N')
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = 0.66;
	}
	else if (data->player_dir == 'S')
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = -0.66;
	}
	else if (data->player_dir == 'W')
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
		data->player->plane_x = -0.66;
		data->player->plane_y = 0;
	}
	else if (data->player_dir == 'E')
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
		data->player->plane_x = 0.66;
		data->player->plane_y = 0;
	}
}

void wall_init(t_data *data)
{
    int x;
    int y;

    x = 64;
    y = 64;
    data->wall[NORTH].img = mlx_xpm_file_to_image(data->screen->mlx, data->no, &x, &y);
    data->wall[NORTH].addr = (int *)mlx_get_data_addr(data->wall[0].img, &data->wall[0].bpp, &data->wall[0].size_line, &data->wall[0].endian);

    data->wall[SOUTH].img = mlx_xpm_file_to_image(data->screen->mlx, data->so, &x, &y);
    data->wall[SOUTH].addr = (int *)mlx_get_data_addr(data->wall[1].img, &data->wall[1].bpp, &data->wall[1].size_line, &data->wall[1].endian);

    data->wall[WEST].img = mlx_xpm_file_to_image(data->screen->mlx, data->we, &x, &y);
    data->wall[WEST].addr = (int *)mlx_get_data_addr(data->wall[2].img, &data->wall[2].bpp, &data->wall[2].size_line, &data->wall[2].endian);

    data->wall[EAST].img = mlx_xpm_file_to_image(data->screen->mlx, data->ea, &x, &y);
    data->wall[EAST].addr = (int *)mlx_get_data_addr(data->wall[3].img, &data->wall[3].bpp, &data->wall[3].size_line, &data->wall[3].endian);
}