#include "cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	key_w(t_data *cub3d)
{
	float	move_speed;

	move_speed = 0.05;
	if (cub3d->map_line[(int)(cub3d->player->pos_x + cub3d->player->dir_x
			* move_speed)][(int)(cub3d->player->pos_y)] == '0'
		|| is_player(cub3d->map_line[(int)(cub3d->player->pos_x
				+ cub3d->player->dir_x
				* move_speed)][(int)(cub3d->player->pos_y)]))
		cub3d->player->pos_x += cub3d->player->dir_x * move_speed;
	if (cub3d->map_line[(int)(cub3d->player->pos_x)][(int)(cub3d->player->pos_y
			+ cub3d->player->dir_y * move_speed)] == '0'
		|| is_player(cub3d->map_line[(int)(cub3d->player->pos_x)]
		[(int)(cub3d->player->pos_y
				+ cub3d->player->dir_y * move_speed)]))
		cub3d->player->pos_y += cub3d->player->dir_y * move_speed;
}

void	key_s(t_data *cub3d)
{
	float	move_speed;

	move_speed = 0.05;
	if (cub3d->map_line[(int)(cub3d->player->pos_x - cub3d->player->dir_x
			* move_speed)][(int)(cub3d->player->pos_y)] == '0'
		|| is_player(cub3d->map_line[(int)(cub3d->player->pos_x
				- cub3d->player->dir_x
				* move_speed)][(int)(cub3d->player->pos_y)]))
		cub3d->player->pos_x -= cub3d->player->dir_x * move_speed;
	if (cub3d->map_line[(int)(cub3d->player->pos_x)][(int)(cub3d->player->pos_y
			- cub3d->player->dir_y * move_speed)] == '0'
		|| is_player(cub3d->map_line[(int)cub3d->player->pos_x]
		[(int)(cub3d->player->pos_y
				- cub3d->player->dir_y * move_speed)]))
		cub3d->player->pos_y -= cub3d->player->dir_y * move_speed;
}

void	key_d(t_data *cub3d)
{
	float	move_speed;

	move_speed = 0.05;
	if (cub3d->map_line[(int)(cub3d->player->pos_x + cub3d->player->dir_y
			* move_speed)][(int)(cub3d->player->pos_y)] == '0'
		|| is_player(cub3d->map_line[(int)(cub3d->player->pos_x
				+ cub3d->player->dir_y
				* move_speed)][(int)(cub3d->player->pos_y)]))
		cub3d->player->pos_x += cub3d->player->dir_y * move_speed;
	if (cub3d->map_line[(int)(cub3d->player->pos_x)][(int)(cub3d->player->pos_y
			- cub3d->player->dir_x * move_speed)] == '0'
		|| is_player(cub3d->map_line[(int)cub3d->player->pos_x]
		[(int)(cub3d->player->pos_y
				- cub3d->player->dir_x * move_speed)]))
		cub3d->player->pos_y -= cub3d->player->dir_x * move_speed;
}

void	key_a(t_data *cub3d)
{
	float	move_speed;

	move_speed = 0.05;
	if (cub3d->map_line[(int)(cub3d->player->pos_x - cub3d->player->dir_y
			* move_speed)][(int)(cub3d->player->pos_y)] == '0'
		|| is_player(cub3d->map_line[(int)(cub3d->player->pos_x
				- cub3d->player->dir_y
				* move_speed)][(int)(cub3d->player->pos_y)]))
		cub3d->player->pos_x -= cub3d->player->dir_y * move_speed;
	if (cub3d->map_line[(int)(cub3d->player->pos_x)][(int)(cub3d->player->pos_y
			+ cub3d->player->dir_x * move_speed)] == '0'
		|| is_player(cub3d->map_line[(int)cub3d->player->pos_x]
		[(int)(cub3d->player->pos_y
				+ cub3d->player->dir_x * move_speed)]))
		cub3d->player->pos_y += cub3d->player->dir_x * move_speed;
}

void	key_right(t_data *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = 0.05;
	old_dir_x = cub3d->player->dir_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(-rot_speed)
		- cub3d->player->dir_y * sin(-rot_speed);
	cub3d->player->dir_y = old_dir_x * sin(-rot_speed) + cub3d->player->dir_y
		* cos(-rot_speed);
	old_plane_x = cub3d->player->plane_x;
	cub3d->player->plane_x = cub3d->player->plane_x * cos(-rot_speed)
		- cub3d->player->plane_y * sin(-rot_speed);
	cub3d->player->plane_y = old_plane_x * sin(-rot_speed)
		+ cub3d->player->plane_y * cos(-rot_speed);
}

void	key_left(t_data *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = 0.05;
	old_dir_x = cub3d->player->dir_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(rot_speed) \
	- cub3d->player->dir_y * sin(rot_speed);
	cub3d->player->dir_y = old_dir_x * sin(rot_speed) \
	+ cub3d->player->dir_y * cos(rot_speed);
	old_plane_x = cub3d->player->plane_x;
	cub3d->player->plane_x = cub3d->player->plane_x \
	* cos(rot_speed)- cub3d->player->plane_y * sin(rot_speed);
	cub3d->player->plane_y = old_plane_x * sin(rot_speed) \
	+ cub3d->player->plane_y * cos(rot_speed);
}