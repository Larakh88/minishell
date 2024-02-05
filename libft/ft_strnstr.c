/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:11:49 by lel-khou          #+#    #+#             */
/*   Updated: 2021/11/21 10:40:18 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*n == 0)
		return ((char *) h);
	while (h[i] != 0 && i < len && len >= ft_strlen(n))
	{
		i = i - j;
		j = 0;
		if (h[i] != n[j])
			i++;
		while (h[i] == n[j] && h[i] != 0 && i < len)
		{
			j++;
			i++;
		}
		if (j == ft_strlen(n))
			return ((char *) h + i - ft_strlen(n));
		i++;
	}
	return (NULL);
}
