/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:44:36 by makbas            #+#    #+#             */
/*   Updated: 2024/01/10 17:53:17 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_control(char *color)
{
	int	i;
	int	comma;
	int	c;
	int	num;

	c = 0;
	i = 0;
	num = 0;
	comma = 0;
	while (color[i])
	{
		if (ft_isdigit(color[i]))
		{
			num++;
			while (ft_isdigit(color[i]))
				i++;
			continue ;
		}
		else if (color[i] == ',')
			comma++;
		else if (color[i] >= 33 && color[i] <= 126)
			c++;
		i++;
	}
	if (c > 0 || comma != 2 || num != 3)
		return (1);
	return (0);
}

int	*color(char *line, int *dir_flag, t_window *window)
{
	char	*color;
	char	**colors;
	int		i;
	int		*c;

	i = 0;
	color = cut_color(line);
	if (color_control(color))
	{
		free(color);
		return (NULL);
	}
	else
	{
		i = 0;
		colors = ft_split(color, ',');
		c = (int *)malloc(sizeof(int) * 3);
		if (c == NULL)
		{
			free(color);
			error("Error : Malloc error", window);
		}
		while (colors[i])
		{
			c[i] = ft_atoi(colors[i]);
			free(colors[i++]);
		}
		if (!is_rgb(c[0]) || !is_rgb(c[1]) || !is_rgb(c[2]))
		{
			free(color);
			free(colors);
			free(c);
			printf("rgb if\n");
			return (NULL);
		}
		free(colors);
	}
	free(color);
	(*dir_flag)++;
	return (c);
}

char	*cut_color(char *line)
{
	char	*dir;
	int		i;

	i = 0;
	dir = line;
	if (*dir)
	{
		dir += 1;
		while (!is_print(*dir))
			dir++;
		while (dir[i] && ft_isprint(dir[i]))
			i++;
	}
	dir = ft_substr(dir, 0, i);
	return (dir);
}
