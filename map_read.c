/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:50:10 by makbas            #+#    #+#             */
/*   Updated: 2024/01/10 17:50:30 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_read_two(t_window *window, int i, int j)
{
	int	len;
	int	x;

	x = 0;
	len = j - i;
	window->map = (char **)malloc(sizeof(char *) * (len + 1));
	if (window->map == NULL)
		error("Error : Malloc error", window);
	while (x < len)
		window->map[x++] = ft_strdup_nospace(window->file_line[i++]);
	window->map[x] = NULL;
}

void	map_read(t_window *window)
{
	int	value[3];

	value[0] = 0;
	while (window->file_line[value[0]])
	{
		if (ft_strchr_one(window->file_line[value[0]]))
			break ;
		value[0]++;
	}
	value[1] = value[0];
	while (window->file_line[value[0]])
	{
		if (!ft_strchr_line(window->file_line[value[0]]))
			break ;
		value[0]++;
	}
	value[2] = value[0];
	while (window->file_line[value[0]])
	{
		if (ft_strchr_line(window->file_line[value[0]]))
			error("Error : Wrong map", window);
		value[0]++;
	}
	map_read_two(window, value[1], value[2]);
}
