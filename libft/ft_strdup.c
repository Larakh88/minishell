/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:43:18 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/07 14:23:07 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof (char) * len + 1);
	if (dest == 0)
		return (0);
	while (i <= len)
	{
		dest[i] = ((unsigned char *)s1)[i];
		i++;
	}
	return (dest);
}
