/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:44:12 by makbas            #+#    #+#             */
/*   Updated: 2024/01/14 16:11:15 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	intro(t_window *window)
{
	window->no = NULL;
	window->so = NULL;
	window->we = NULL;
	window->ea = NULL;
	window->f = NULL;
	window->c = NULL;
	window->file_line = NULL;
	window->map = NULL;
}

void	control(int ac, char *av, t_window *window)
{
	if (ac != 2)
		error("Error : Wrong number of arguments", window);
	if (ft_strncmp(av + ft_strlen(av) - 4, ".cub", 4))
		error("Error : Wrong file format", window);
	if (file_read(window, av))
		error("\0", window);
	if (dir_control(window))
		error("Error : Wrong directory file or color", window);
	map_read(window);
	window->name = ft_strdup(av);
	if (element_c(window) || valid_c(window))
		error("Error: Wrong map", window);
}

int	main(int ac, char **av)
{
	t_window	window;

	intro(&window);
	control(ac, av[1], &window);

	free_file(&window);
	free_map(&window);
	free_directory(&window);
	//system("leaks cub3d");
	return (0);
}
