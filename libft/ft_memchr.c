/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:56:46 by lel-khou          #+#    #+#             */
/*   Updated: 2021/10/15 16:59:31 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*d;

	d = (char *)s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
