/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:30 by makbas            #+#    #+#             */
/*   Updated: 2022/10/16 18:45:27 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst && !dstsize)
		return (0);
	i = ft_strlen(dst);
	if (i >= dstsize)
		return (ft_strlen(src) + dstsize);
	ft_strlcpy((dst + i), src, dstsize - i);
	return (i + ft_strlen(src));
}
