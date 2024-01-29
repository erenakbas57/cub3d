/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:48:11 by makbas            #+#    #+#             */
/*   Updated: 2024/01/10 14:49:09 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*wall_file(char *line, int *dir_flag)
{
	char	*dir;
	int		fd;

	dir = cut_dir(line);
	if (ft_strncmp(dir + ft_strlen(dir) - 4, ".xpm", 4))
	{
		free(dir);
		return (NULL);
	}
	fd = open(dir, O_RDONLY);
	if (fd < 0)
	{
		free(dir);
		return (NULL);
	}
	close(fd);
	(*dir_flag)++;
	return (dir);
}

char	*cut_dir(char *line)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	line += 2;
	while (!is_print(*line))
		line++;
	while (line[i] && is_print(line[i]))
		i++;
	tmp = line;
	line = ft_substr(line, 0, i);
	while (tmp[i])
	{
		if (tmp[i] > 32 && tmp[i] < 127)
			c++;
		i++;
	}
	if (c != 0)
	{
		free(line);
		return (ft_strdup(" "));
	}
	return (line);
}