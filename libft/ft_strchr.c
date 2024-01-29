/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:12 by makbas            #+#    #+#             */
/*   Updated: 2024/01/10 14:40:55 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

int	ft_strchr_one(char *line)
{
	int	count;

	count = 0;
	if (!ft_strchr_line(line))
		return (0);
	while (*line != '\0' && *line != '\n')
	{
		if (*line != '1' && *line != 32)
			count++;
		line++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int	ft_strchr_line(char *s)
{
	while (*s != '\0' && *s != '\n')
	{
		if (*s >= 33 && *s <= 126)
			return (1);
		s++;
	}
	return (0);
}
