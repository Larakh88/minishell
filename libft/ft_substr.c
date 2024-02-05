/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:31:59 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/01 18:26:24 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (0);
	while (i < len && start < ft_strlen(s))
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
