/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:54:17 by makbas            #+#    #+#             */
/*   Updated: 2024/01/10 18:00:57 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_free(t_window *window)
{
	free_file(window);
	free_directory(window);
	free_map(window);
	free(window->name);
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

void	free_file(t_window *window)
{
	int	i;

	i = 0;
	if (window->file_line)
	{
		while (window->file_line[i])
		{
			free(window->file_line[i]);
			i++;
		}
		free(window->file_line);
	}
}

void	free_map(t_window *window)
{
	int	i;

	i = 0;
	if (window->map)
	{
		while (window->map[i])
		{
			free(window->map[i]);
			i++;
		}
		free(window->map);
	}
}

void	free_directory(t_window *window)
{
	if (window->no)
		free(window->no);
	if (window->so)
		free(window->so);
	if (window->we)
		free(window->we);
	if (window->ea)
		free(window->ea );
	if (window->f)
		free(window->f);
	if (window->c)
		free(window->c);
}
