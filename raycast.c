#include "cub3d.h"

int	render(t_data *data)
{
	prep(data);
	raycast(data);
	key(data);
	return (0);
}


void	key(t_data *cub3d)
{
	if (cub3d->keys->w)
		key_w(cub3d);
	else if (cub3d->keys->s)
		key_s(cub3d);
	else if (cub3d->keys->left)
		key_left(cub3d);
	else if (cub3d->keys->right)
		key_right(cub3d);
	else if (cub3d->keys->d)
		key_d(cub3d);
	else if (cub3d->keys->a)
		key_a(cub3d);
}

void prep(t_data *data)
{
    int y;
    int x;

    y = 0;
	mlx_destroy_image(data->screen->mlx, data->screen->img);
	data->screen->img = mlx_new_image(data->screen->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->screen->addr = (int *)mlx_get_data_addr(data->screen->img, &data->screen->bpp, &data->screen->size_line, &data->screen->endian);
	while (y < WIN_WIDTH)
	{
		x = 0;
		while (x < WIN_HEIGHT)
		{
			if (x < WIN_HEIGHT / 2)
                data->screen->addr[x * WIN_WIDTH + y] = data->screen->ceiling;
			else
				data->screen->addr[x * WIN_WIDTH + y] = data->screen->floor;
			x++;
		}
		y++;
	}
}

void	raycast(t_data *data)
{
	int	i;

	i = 0;

	while (i < (data->screen->width))
	{
		data->ray->camera_x = 2 * i / (double)data->screen->width - 1;
		data->ray->raydir_x = data->player->dir_x + data->player->plane_x
			* data->ray->camera_x;
		data->ray->raydir_y = data->player->dir_y + data->player->plane_y
			* data->ray->camera_x;	
		data->ray->map_x = (int)data->player->pos_x;
		data->ray->map_y = (int)data->player->pos_y;
		raycast2(data, i);
		i++;
	}
	mlx_put_image_to_window(data->screen->mlx, data->screen->mlx_win,
		data->screen->img, 0, 0);
}

void	raycast2(t_data *data, int i)
{
	if (data->ray->raydir_x == 0) //çzigi x eksenine paralel demek ve hiçirşeye çarpmayacak demek
		data->ray->delta_dist_x = 1e30;
	else
		data->ray->delta_dist_x = fabs(1 / data->ray->raydir_x); //çizginin sınıra laşmak için gerken mesafeini bulur
	if (data->ray->raydir_y == 0)
		data->ray->delta_dist_y = 1e30;
	else
		data->ray->delta_dist_y = fabs(1 / data->ray->raydir_y);
	dir(data);
	hit(data);
	dist(data);
	text(data, i);
}

//hareket yönü ve sınırlar uzaklık belirlemek için kullanılır
void	dir(t_data *data)
{
	if (data->ray->raydir_x < 0) // çizgiler sola doğru demektir-> burada step_x'e -1 verekrek bir belirteç gibi kullanıyoruz
	{
		data->ray->step_x = -1;
		data->ray->side_dist_x = (data->player->pos_x - data->ray->map_x) * data->ray->delta_dist_x;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->side_dist_x = (data->ray->map_x + 1 - data->player->pos_x) * data->ray->delta_dist_x;
	}
	if (data->ray->raydir_y < 0)
	{
		data->ray->step_y = -1;
		data->ray->side_dist_y = (data->player->pos_y - data->ray->map_y)
			* data->ray->delta_dist_y;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->side_dist_y = (data->ray->map_y + 1 - data->player->pos_y) * data->ray->delta_dist_y;
	}
	
}
//çizilen bir ray hücre sınırına çarptı  mı çarpmadı mı  kontrolu 
void	hit(t_data *data)
{
	data->ray->hit = 0;
	while (data->ray->hit == 0)
	{
		if (data->ray->side_dist_x < data->ray->side_dist_y)
		{
			data->ray->side_dist_x += data->ray->delta_dist_x; 
			data->ray->map_x += data->ray->step_x; //step_x ve step_y hareket yönelrini belirleyen-1 ve 1 eğerleriydi ve map_x knumunu buna göre güncelliyor
			data->ray->side = 0; 
		}
		else
		{
			data->ray->side_dist_y += data->ray->delta_dist_y;
			data->ray->map_y += data->ray->step_y;
			data->ray->side = 1;
		}
		if (data->map_line[(int)data->ray->map_x][(int)data->ray->map_y] == '1') // çzgin ulaştığı hücre sınırının harita üzerindeki değeri kontol edilir-> u değer bir sie vurdu anlamına gelir ve döngü biter adım adım yapılan resimdeki işlemmiş yani
			data->ray->hit = 1;
	}
}


//en önemli fonksion, önceki fonksiyonda duvara çarpma olmadığı zmaanalrda side_dist_x değerlerine falan atamalar yaptık->
//şimdi çizginin çarptığı duvarın uzaklığı, çizginin ekran alt üst kenarları arasındaki yüksekliğini ve çizilecek
//olan duvarın ekran üzerindkei başlangıç ve bitiş noktaları hesaplanır-> 
void	dist(t_data *data)
{
	if (data->ray->side == 0) //ray x ekseninde bir hücre sınırına çarpıyor-> 
		data->ray->perp_wall_dist = data->ray->side_dist_x
			- data->ray->delta_dist_x; //perpendicular wall distance-> çizilen rayin çarptığı duvarın dik mesafesini ifade eder->
	else
		data->ray->perp_wall_dist = data->ray->side_dist_y
			- data->ray->delta_dist_y;
	data->ray->line_height = (int)(1080 / data->ray->perp_wall_dist);
	//1080 ile oranlayarak yüksekliğini bulacak-> duvaın ekrandaki yüksekliği-> perp_wall arttıkça line height küçülecek
	data->ray->draw_start = -data->ray->line_height / 2 + 1080 / 2;
	//duvarın ekran üzerindeki başlama noktasını bulur-> 1080 ekran yüksekliğiydi
	if (data->ray->draw_start < 0)
		data->ray->draw_start = 0;
	//duvara çok yakınsan tüm ekran duvar olacak
	data->ray->draw_end = data->ray->line_height / 2 + 1080 / 2;
	//duvarın tepe noktasının ekrandaki yerş
	if (data->ray->draw_end >= 1080)
		data->ray->draw_end = 1080 - 1;
		//duvara çok yakınsan tüm ekran duvar olacak

}

//çizilen ray'in çarptığı duavrın texture kordinatlarını hesaplar
void	init_text(t_data *data)
{
	double	wallx;

	data->ray->text_num = data->map_line[(int)data->ray->map_x]
	[(int)data->ray->map_y] - 1;
	//bir çıkarmanın nedenini anlaamdık ama herbir x ve y değeri alınıyor ve bunlaın 0 veya 1 değerleri kontrol ediliyor gibi gözüküyor duvar mı boşlık mu
	if (data->ray->side == 0) //x ekseninde bir hücre sınırına çarpıyor
		wallx = data->player->pos_y + data->ray->perp_wall_dist
			* data->ray->raydir_y;
		//çizilen ray'in çaptığı duvarın üzerindeki konumu
	else
		wallx = data->player->pos_x + data->ray->perp_wall_dist
			* data->ray->raydir_x;
	wallx -= floor(wallx); //wallx değerini ondalık kısmından arındırıp 0 1  arlaığına normalie eder-> bu textue de hangi kordinatın kullanılacağını belirler
	data->ray->text_x = (int)(wallx * (double)64); //wallx değerine göre texturde hangi  x kordinatının seçileceğini belirler, pixel pixel ilerleme devam
	if (data->ray->side == 0 && data->ray->raydir_x > 0)
		data->ray->text_x = 64 - data->ray->text_x - 1; //ğer çizgi dikey bir hücre sınırına çarpıyorsa ve çizgi sağa doğru hareket ediyorsa, textürün sağ yarısını kullanmak için data->player->text_x değeri düzeltilir->
	if (data->ray->side == 1 && data->ray->raydir_y < 0)
		data->ray->text_x = 64 - data->ray->text_x - 1; 
	data->ray->tex_step = 1.0 * 64 / data->ray->line_height; //textur kordinatları arasındaki (birim miktarı) adımı belirler-> texture genişliği ile çizilen rayin çarptığı duvarın yükseklik oranı kullanılır
	//meslea textur gen: 64, kordinatlar arası birim miktar 1/64 olur-> bu adımda ise bunu çizginin bıyutu(32 olsun mesela)
	//çarparsak 0->5 birim elde ederiz e texturedaki herhangi bir pixel 0->5 birim uzaklıkta demektir	
	data->ray->tex_pos = (data->ray->draw_start - 1080 / 2
			+ data->ray->line_height / 2) * data->ray->tex_step;
}

//bu kordinat bilgileri alınmış texturu bölgesine çizer 
void	text(t_data *data, int x)
{
	int	texty;

	init_text(data);
	while (data->ray->draw_start < data->ray->draw_end)
	{
		texty = (int)data->ray->tex_pos & (64 - 1);
		//& bitwie and operator
		data->ray->tex_pos += data->ray->tex_step;  //her adımda duvar üzerinde bir çizginin üzerine düşen ışık ışınlarını temsil eder 
		//Güneye Bakış, Pozitif X Yönü: no_data dizisi içinden bir textur belrileme yapar
		if (data->ray->side == 0 && data->ray->raydir_x > 0)
			data->screen->addr[data->ray->draw_start * data->screen->width
				+ x] = data->wall[SOUTH].addr[64 * texty + data->ray->text_x];
		else if (data->ray->side == 0 && data->ray->raydir_x < 0) //Güneye Bakış, Negatif X Yönü: no_data dizisi içinden bir textur belrileme yapar
			data->screen->addr[data->ray->draw_start * data->screen->width
				+ x] = data->wall[NORTH].addr[64 * texty + data->ray->text_x];
		else if (data->ray->side == 1 && data->ray->raydir_y > 0) //doğuya Bakış, pozitif y Yönü: ea_data dizisi içinden bir textur belrileme yapar
			data->screen->addr[data->ray->draw_start * data->screen->width
				+ x] = data->wall[EAST].addr[64 * texty + data->ray->text_x];
		else //doğuya Bakış, pozitif y Yönü: we_data dizisi içinden bir textur belrileme yapar
			data->screen->addr[data->ray->draw_start * data->screen->width
				+ x] = data->wall[WEST].addr[64 * texty + data->ray->text_x];
		data->ray->draw_start++;
		//Bu if-else blokları, duvarın konumuna ve rayin hareket yönüne bağlı olarak doğru duvar tekstürünü seçerek ekrana çizmeyi sağlar->
	}
}