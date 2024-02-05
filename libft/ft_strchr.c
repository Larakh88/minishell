/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:31:59 by lel-khou          #+#    #+#             */
/*   Updated: 2021/11/21 10:39:08 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (c == 0)
		return ((char *)(str + ft_strlen(str)));
	if (str == NULL)
		return (NULL);
	while (str[i] != 0)
	{
		if (str[i] == (char)c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}
