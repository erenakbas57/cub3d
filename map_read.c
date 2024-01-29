/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:50:10 by makbas            #+#    #+#             */
/*   Updated: 2024/01/29 16:31:19 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_read_two(t_data *data, int i, int j)
{
	int	len;
	int	x;

	x = 0;
	len = j - i;
	data->map_size = len;
	data->map_line = (char **)malloc(sizeof(char *) * (len + 1));
	if (data->map_line == NULL)
		error("Error : Malloc error", data);
	while (x < len)
		data->map_line[x++] = ft_strdup_nospace(data->file_line[i++]);
	data->map_line[x] = NULL;
}

void	map_read(t_data *data)
{
	int	value[3];

	value[0] = 0;
	while (data->file_line[value[0]])
	{
		if (ft_strchr_one(data->file_line[value[0]]))
			break ;
		value[0]++;
	}
	value[1] = value[0];
	while (data->file_line[value[0]])
	{
		if (!ft_strchr_line(data->file_line[value[0]]))
			break ;
		value[0]++;
	}
	value[2] = value[0];
	while (data->file_line[value[0]])
	{
		if (ft_strchr_line(data->file_line[value[0]]))
			error("Error : Wrong map", data);
		value[0]++;
	}
	map_read_two(data, value[1], value[2]);
}
