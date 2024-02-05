/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:08:57 by lel-khou          #+#    #+#             */
/*   Updated: 2021/11/21 10:25:32 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	j;
	size_t	k;

	j = 0;
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	size = ft_strlen(src) + ft_strlen(dst);
	k = ft_strlen(dst);
	while (k < (dstsize - 1) && src[j] != 0)
	{
		dst[k] = src[j];
		k++;
		j++;
	}
	dst[k] = '\0';
	return (size);
}
