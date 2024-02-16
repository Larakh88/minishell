/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:04:34 by lel-khou          #+#    #+#             */
/*   Updated: 2022/10/28 13:27:03 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count(char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (count < 2)
			while (s[i] == ' ' && s[i] != 0)
				i++;
		if (i == ft_strlen(s))
			return (count);
		if (s[i] == 34)
			i = ft_skip(s, i + 1, 34) + 1;
		else if (s[i] == 39)
			i = ft_skip(s, i + 1, 39) + 1;
		else if (s[i] == ' ')
			while (s[i] == ' ' && s[i] != 0)
				i++;
		else
			while (s[i] != ' ' && s[i] != 0 && s[i] != 34 && s[i] != 39)
				i++;
		count++;
	}
	return (count);
}

static char	*split_parse(t_data *ptr, int j)
{
	char	*split;

	if (j < 2)
		ptr->i = skip_space(ptr);
	if (ptr->s[ptr->i] == 34)
		split = dup_dquotes(ptr);
	else if (ptr->s[ptr->i] == 39)
		split = dup_squotes(ptr);
	else if (ptr->s[ptr->i] == ' ')
	{
		split = ft_strdup(" ");
		while (ptr->s[ptr->i] == ' ' && ptr->s[ptr->i] != 0)
			ptr->i++;
	}
	else
		split = dup_word(ptr);
	return (split);
}

char	**ft_split_single(t_data *ptr)
{
	int		count;
	char	**split;
	int		j;

	j = 0;
	ptr->i = 0;
	if (!ptr->s)
		return (0);
	count = ft_count(ptr->s);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	while (j < count)
	{
		split[j] = split_parse(ptr, j);
		j++;
	}
	split[j] = NULL;
	ptr->i = 0;
	return (split);
}
