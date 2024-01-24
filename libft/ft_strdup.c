/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:15 by makbas            #+#    #+#             */
/*   Updated: 2024/01/10 14:43:35 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printlen(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (ft_isprint_nospace(str[i]))
			c++;
		i++;
	}
	return (c);
}

char	*ft_strdup(const char *str)
{
	char	*d;
	int		i;

	i = 0;
	d = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (d == NULL)
		return (0);
	while (str[i] != '\0')
	{
		d[i] = str[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strdup_nospace(char *str)
{
	char	*d;
	int		i;
	int		j;

	j = 0;
	i = 0;
	d = malloc(sizeof(char) * (ft_printlen(str) + 1));
	if (d == NULL)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		if (ft_isprint_nospace(str[i]))
		{
			d[j] = str[i];
			j++;
		}
		i++;
	}
	d[j] = '\0';
	return (d);
}
