/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:27:08 by makbas            #+#    #+#             */
/*   Updated: 2024/01/10 18:00:36 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(char *str, t_window *window)
{
	free_map(window);
	free_file(window);
	free_directory(window);
	printf("%s\n", str);
	//system("leaks cub3d");
	exit(0);
}
