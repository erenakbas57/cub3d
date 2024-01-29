/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:55:45 by makbas            #+#    #+#             */
/*   Updated: 2024/01/17 18:06:47 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dir_control(t_data *data)
{
	int			i;
	static int	dir;
	static int	fill_len;

	i = 0;
	dir = 0;
	fill_len = 0;
	while (data->file_line[i])
	{
		directory_cmp(data, &dir, &i);
		if (ft_strchr_line(data->file_line[i]))
			fill_len++;
		if (ft_strchr_one(data->file_line[i]))
			break ;
		i++;
	}
	if (dir != 6 || fill_len > 7)
		return (1);
	return (0);
}

void	directory_cmp(t_data *data, int *dir, int *i)
{
	char	*tmp;

	tmp = data->file_line[*i];
	if (!(ft_strncmp(tmp, "NO", 2)))
		data->no = wall_file(tmp, dir);
	else if (!(ft_strncmp(tmp, "SO", 2)))
		data->so = wall_file(tmp, dir);
	else if (!(ft_strncmp(tmp, "WE", 2)))
		data->we = wall_file(tmp, dir);
	else if (!(ft_strncmp(tmp, "EA", 2)))
		data->ea = wall_file(tmp, dir);
	else if (!(ft_strncmp(tmp, "F", 1)))
		data->f = color(tmp, dir, data);
	else if (!(ft_strncmp(tmp, "C", 1)))
		data->c = color(tmp, dir, data);
}

int	is_print(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

int	is_rgb(int nbr)
{
	if (nbr >= 0 && nbr <= 255)
		return (1);
	return (0);
}
