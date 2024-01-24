/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:55:45 by makbas            #+#    #+#             */
/*   Updated: 2024/01/10 17:53:01 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dir_control(t_window *window)
{
	int			i;
	static int	dir;
	static int	fill_len;

	i = 0;
	dir = 0;
	fill_len = 0;
	while (window->file_line[i])
	{
		directory_cmp(window, &dir, &i);
		if (ft_strchr_line(window->file_line[i]))
			fill_len++;
		if (ft_strchr_one(window->file_line[i]))
			break ;
		i++;
	}
	if (dir != 6 || fill_len > 7)
		return (1);
	return (0);
}

void	directory_cmp(t_window *window, int *dir, int *i)
{
	char	*tmp;

	tmp = window->file_line[*i];
	if (!(ft_strncmp(tmp, "NO", 2)))
		window->no = wall_file(tmp, dir);
	else if (!(ft_strncmp(tmp, "SO", 2)))
		window->so = wall_file(tmp, dir);
	else if (!(ft_strncmp(tmp, "WE", 2)))
		window->we = wall_file(tmp, dir);
	else if (!(ft_strncmp(tmp, "EA", 2)))
		window->ea = wall_file(tmp, dir);
	else if (!(ft_strncmp(tmp, "F", 1)))
		window->f = color(tmp, dir, window);
	else if (!(ft_strncmp(tmp, "C", 1)))
		window->c = color(tmp, dir, window);
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
