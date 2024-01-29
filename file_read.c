/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:53:40 by makbas            #+#    #+#             */
/*   Updated: 2024/01/29 18:51:40 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_len(char *name)
{
	int		fd;
	int		len;
	char	c;

	len = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (1);
	while (read(fd, &c, sizeof(char)) > 0)
	{
		if (c == '\n')
			len++;
	}
	len++;
	close(fd);
	return (len);
}

void	last_line(t_data *data, int *i, int *j, char *line)
{
	if (*j > 0)
	{
		line[(*j)++] = '\0';
		data->file_line[(*i)++] = ft_strdup(line);
	}
	data->file_line[*i] = NULL;
}

int	file_read(t_data *data, char *f_name)
{
	int		fd;
	int		c;
	char	*line;
	int		i;
	int		j;
	int		len;

	len = file_len(f_name);
	fd = open(f_name, O_RDONLY);
	if (len == -1 || fd == -1)
		return (printf("Error : File isn't open or exist\n"));
	i = 0;
	data->file_line = (char **)malloc(sizeof(char *) * (len + 1)); // yer açtı
	line = (char *)malloc(sizeof(char) * 1024); // freelendi
	if (!line || !data->file_line)
		return (printf("Error : Malloc error\n"));
	j = 0;
	while (read(fd, &c, sizeof(char)) > 0)
	{
		line[j++] = c;
		if (c == '\n')
		{
			line[j] = '\0';
			data->file_line[i++] = ft_strdup(line);
			j = 0;
		}
	}
	last_line(data, &i, &j, line);
	free(line);
	close(fd);
	return (0);
}
