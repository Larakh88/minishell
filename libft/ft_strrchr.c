/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:15:45 by lel-khou          #+#    #+#             */
/*   Updated: 2021/11/21 10:41:17 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (str == 0)
		return (NULL);
	if (c == 0)
		return ((char *)(str + i));
	while (i > 0)
	{
		if (str[i] == (char)c)
		{
			return ((char *)(str + i));
		}
		i--;
	}
	if (str[i] == (char)c)
		return ((char *)str);
	return (NULL);
}
