/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:01:23 by lel-khou          #+#    #+#             */
/*   Updated: 2021/10/15 17:04:26 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_start(char const *s1, char const *set, size_t i)
{
	size_t	j;
	size_t	lenset;
	char	s;

	j = 0;
	s = s1[i];
	lenset = ft_strlen(set);
	while (j <= lenset)
	{
		if (s != set[j])
			j++;
		else
			break ;
	}
	if (j == lenset + 1)
		return (0);
	else
		return (1);
}

size_t	ft_end(char const *s1, char const *set, size_t j)
{
	size_t	i;
	char	s;
	size_t	lens1;

	i = 0;
	lens1 = ft_strlen(s1);
	s = s1[lens1 - j];
	while (i < ft_strlen(set))
	{
		if (s != set[i])
			i++;
		else
			break ;
	}
	if (i == ft_strlen(set))
		return (0);
	else
		return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 1;
	if (!s1 || !set)
		return (0);
	while (ft_start(s1, set, i) != 0)
	{
		i++;
	}
	while (ft_end(s1, set, k) != 0)
	{
		k++;
	}
	k = k - 1;
	return (ft_substr(s1, i, ft_strlen(s1) - i - k));
}
