/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:44 by makbas            #+#    #+#             */
/*   Updated: 2022/10/11 16:10:45 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[h] != '\0' && h < len)
	{
		n = 0;
		while (haystack[h + n] == needle[n] && needle[n] != 0 && n + h < len)
			n++;
		if (n == ft_strlen(needle))
			return ((char *)&haystack[h]);
		h++;
	}
	return (0);
}
