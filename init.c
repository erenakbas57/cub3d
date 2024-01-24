/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:00:53 by makbas            #+#    #+#             */
/*   Updated: 2024/01/14 16:16:31 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init(t_window *window)
{
    init_player(window);
}

void init_player(t_window *window)
{
    window->player->pos_y = window->player_loc[0];
    window->player->pos_x = window->player_loc[1];
    window->player->plane_x = 0;
    window->player->plane_y = 0.66;
    window->player->move_speed = 0.05;
    window->player->rot_speed = 0.05;
    window->player->dir = window->player_dir;
    
    // Başlangıç yönünü ayarla
    if (window->player->dir == 'N')
    {
        
    }
        set_direction(&map->player.dir_x, &map->player.plane_x, 0.0, -1.0);
    else if (start_dir == 'S')
        set_direction(&map->player.dir_x, &map->player.plane_x, 0.0, 1.0);
    else if (start_dir == 'W')
        set_direction(&map->player.dir_x, &map->player.plane_x, -1.0, 0.0);
    else if (start_dir == 'E')
        set_direction(&map->player.dir_x, &map->player.plane_x, 1.0, 0.0);

}