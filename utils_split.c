/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:01:35 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/02 17:44:28 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_skip(char *s, int i, char c)
{
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

char	*dup_dquotes(t_data *ptr)
{
	char	*dest;
	int		j;

	j = ptr->i + 1;
	ptr->i = ft_skip(ptr->s, j, 34);
	dest = ft_substr(ptr->s, j, ptr->i - j);
	ptr->i++;
	return (dest);
}

char	*dup_squotes(t_data *ptr)
{
	char	*dest;
	int		j;

	j = ptr->i + 1;
	ptr->i = ft_skip(ptr->s, j, 39);
	dest = ft_substr(ptr->s, j, ptr->i - j);
	ptr->i++;
	return (dest);
}

char	*dup_word(t_data *ptr)
{
	char	*dest;
	int		j;

	j = ptr->i;
	while (ptr->s[ptr->i] != ' ' && ptr->s[ptr->i] != 0 \
	&& ptr->s[ptr->i] != 34 && ptr->s[ptr->i] != 39)
		ptr->i++;
	dest = ft_substr(ptr->s, j, ptr->i - j);
	return (dest);
}

int	skip_space(t_data *ptr)
{
	while (ptr->s[ptr->i] != 0 && ptr->s[ptr->i] == ' ')
		ptr->i++;
	return (ptr->i);
}
