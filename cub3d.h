/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:26:05 by makbas            #+#    #+#             */
/*   Updated: 2024/01/14 16:14:55 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define MAP_CHAR "01NSEW"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_ray
{
	double	camera_x;      // Kamera düzlemindeki x koordinatı (perspektif etkisi için)
	double	dir_x;         // Ray'in x yönündeki vektör bileşeni
	double	dir_y;         // Ray'in y yönündeki vektör bileşeni
	int		map_x;         // Ray'in harita üzerindeki konumu (x)
	int		map_y;         // Ray'in harita üzerindeki konumu (y)
	double	side_dist_x;   // İlk çarpışma noktasından sonraki x yönde adım başına uzaklık
	double	side_dist_y;   // İlk çarpışma noktasından sonraki y yönde adım başına uzaklık
	double	delta_dist_x;  // Ray'in x yönde adım başına uzaklığı
	double	delta_dist_y;  // Ray'in y yönde adım başına uzaklığı
	double	perp_wall_dist;// Duvarın oyuncuya olan dik uzaklığı
	int		step_x;        // Harita üzerinde x yönde bir adımın pozitif veya negatif olup olmadığını belirten değer
	int		step_y;        // Harita üzerinde y yönde bir adımın pozitif veya negatif olup olmadığını belirten değer
	int		side;           // Çarpışmanın hangi yüzeyde (duvarın önü/arkası) olduğunu belirten değer
}	t_raycaster;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_map
{
	char	**window;
	char	*window_name;
	int		map_width;
	int		map_height;

}	t_map;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_image		*north;
	t_image		*south;
	t_image		*west;
	t_image		*east;

	t_player	*player;
	t_raycaster	*ray;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;

	int			*f;
	int			*c;

	char		**file_line;
	char		**map;
	char		*name;
	int			player_loc[2];
	char		player_dir;
}	t_window;

int		*color(char *line, int *dir_flag, t_window *window);
int		color_control(char *color);
char	*cut_color(char *line);

int		dir_control(t_window *window);
void	directory_cmp(t_window *window, int *dir, int *i);
int		is_print(char c);
int		is_rgb(int nbr);

char	*wall_file(char *line, int *dir_flag);
char	*cut_dir(char *line);

int		error(char *str, t_window *window);

void	map_read(t_window *window);

int		element_c(t_window *window);
int		valid_c(t_window *window);
void	recursive_p(t_window *window, char **window_l, int y, int x);

int		file_len(char *name);
void	last_line(t_window *window, int *i, int *j, char *line);
int		file_read(t_window *window, char *f_name);

void	free_map(t_window *window);
void	free_directory(t_window *window);
void	free_array(char **array);
void	free_file(t_window *window);

void	intro(t_window *window);
void	control(int ac, char *av, t_window *window);

void	recursive_p(t_window *window, char **window_l, int y, int x);
int		valid_c(t_window *window);
int		element_c(t_window *window);

void	map_read_two(t_window *window, int i, int j);
void	map_read(t_window *window);

#endif