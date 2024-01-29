/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:54:17 by makbas            #+#    #+#             */
/*   Updated: 2024/01/17 20:22:08 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_free(t_data *data)
{
	free_file(data);
	free_directory(data);
	free_map(data);
	free(data->name);
	free(data->player);
	free(data->wall);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	free_file(t_data *data)
{
	int	i;

	i = 0;
	if (data->file_line)
	{
		while (data->file_line[i])
		{
			free(data->file_line[i]);
			i++;
		}
		free(data->file_line);
	}
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map_line)
	{
		while (data->map_line[i])
		{
			free(data->map_line[i]);
			i++;
		}
		free(data->map_line);
	}
}

void	free_directory(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea );
	if (data->f)
		free(data->f);
	if (data->c)
		free(data->c);
}
