/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:32:46 by lel-khou          #+#    #+#             */
/*   Updated: 2021/11/21 10:34:58 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int n)
{
	long	nbr;
	int		i;

	nbr = n;
	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nbr;
	int		i;

	nbr = n;
	i = ft_size(n);
	s = malloc(sizeof (char) * i + 1);
	if (s == 0)
		return (0);
	if (nbr < 0)
	{
		nbr = -nbr;
		s[0] = '-';
	}
	s[i] = 0;
	while (nbr >= 10)
	{
		s[--i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (nbr < 10)
		s[--i] = nbr + '0';
	return (s);
}
