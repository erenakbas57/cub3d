/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:26:05 by makbas            #+#    #+#             */
/*   Updated: 2024/01/29 18:58:33 by makbas           ###   ########.fr       */
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
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef struct s_keys
{
	int w;
	int a;
	int s;
	int d;
	int right;
	int left;
}	t_keys;

typedef struct s_ray
{
	double	camera_x;      // Kamera düzlemindeki x koordinatı (perspektif etkisi için)
	double	raydir_x;         // Ray'in x yönündeki vektör bileşeni
	double	raydir_y;         // Ray'in y yönündeki vektör bileşeni
	double	map_x;         // Ray'in harita üzerindeki konumu (x)
	double	map_y;         // Ray'in harita üzerindeki konumu (y)
	double	side_dist_x;   // İlk çarpışma noktasından sonraki x yönde adım başına uzaklık
	double	side_dist_y;   // İlk çarpışma noktasından sonraki y yönde adım başına uzaklık
	double	delta_dist_x;  // Ray'in x yönde adım başına uzaklığı
	double	delta_dist_y;  // Ray'in y yönde adım başına uzaklığı
	double	perp_wall_dist;// Duvarın oyuncuya olan dik uzaklığı
	
	double	step; //raydir_x yada raydir_y e göre bir birimlik adımın bir hücre sınırına ulaşması için gereken mesafe
	double	tex_pos; // duvarın nereden başlayacağını tutar
	double	tex_step; //duvarın bir sonraki pikselinin nereden başlayacağını tutar

	int		line_height; // duvarın yüksekliği
	int		hit; //çizginin bir duvara çarpıp çarpmadığını tutar
	int		side; //çizginin hangi yönden geldiğini tutar
	int		step_x; //çizginin x eksenindeki adımını tutar
	int		step_y; //çizginin y eksenindeki adımını tutar
	int		draw_start; //duvarın çiziminin nereden başlayacağını tutar
	int		draw_end; //duvarın çiziminin nerede biteceğini tutar
	int		text_num; //duvarın hangi yönden geldiğini tutar
	int		text_x; //duvarın hangi pikselinden başlayacağını tutar
}	t_raycaster;

typedef struct s_player
{
	char	loc;
	double	pos_x;
	double	pos_y;
	double	dir_x;	
	double	dir_y;
	double	plane_x; // Kamera düzlemindeki x koordinatı (perspektif etkisi için)
	double	plane_y; // Kamera düzlemindeki y koordinatı (perspektif etkisi için)

	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_image
{
	void	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;


typedef struct s_screen
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
	long	floor;
	long	ceiling;
	int		width;
	int		height;
}	t_screen;



typedef struct s_data
{
	t_screen	*screen;
	int			*f;
	int			*c;

	char		**map_line;
	int			map_size;
	char		*name;
	char		**file_line;
	
	t_player	*player;
	t_keys		*keys;
	int			player_loc[2];
	char		player_dir;


	t_image		*wall;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	

	t_raycaster	*ray;
	
	
}	t_data;

int		*color(char *line, int *dir_flag, t_data *data);
int		color_control(char *color);
char	*cut_color(char *line);

int		dir_control(t_data *data);
void	directory_cmp(t_data *data, int *dir, int *i);
int		is_print(char c);
int		is_rgb(int nbr);

char	*wall_file(char *line, int *dir_flag);
char	*cut_dir(char *line);

int		error(char *str, t_data *data);

int		element_c(t_data *data);
int		valid_c(t_data *data);
void	recursive_p(t_data *data, char **window_l, int y, int x);

int		file_len(char *name);
void	last_line(t_data *data, int *i, int *j, char *line);
int		file_read(t_data *data, char *f_name);

void	free_map(t_data *data);
void	free_directory(t_data *data);
void	free_array(char **array);
void	free_file(t_data *data);
void	all_free(t_data *data);

void	intro(t_data *data);
void	control(int ac, char *av, t_data *data);

void	recursive_p(t_data *data, char **window_l, int y, int x);
int		valid_c(t_data *data);
int		element_c(t_data *data);

void	map_read_two(t_data *data, int i, int j);
void	map_read(t_data *data);



void	init(t_data *data);
void 	keys_init(t_data *data);
void 	player_init(t_data *data);
void 	wall_init(t_data *data);

int	render(t_data *data);
void prep(t_data *data);



void 	raycast(t_data *data);
void 	raycast2(t_data *data, int i);
void	dist(t_data *data);
void	hit(t_data *data);
void	dir(t_data *data);
void	init_text(t_data *data);
void	text(t_data *data, int x);

int	close_window(t_data *cub3d);

void	key(t_data *cub3d);
void	key_left(t_data *cub3d);
void	key_right(t_data *cub3d);
void	key_w(t_data *cub3d);
void	key_s(t_data *cub3d);
void	key_d(t_data *cub3d);
void	key_a(t_data *cub3d);
int	is_player(char c);
#endif