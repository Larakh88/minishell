/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:22:25 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/12 14:27:43 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init(t_data *ptr)
{
	ptr->j = 0;
	ptr->vlength = 0;
	ptr->vstart = 0;
	ptr->qflag = 0;
}

static	char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*temp;
	char	*dest;

	temp = ft_strjoin(s1, s2);
	dest = ft_strjoin(temp, s3);
	free (temp);
	return (dest);
}

static int	ft_check(t_data *ptr, char *str)
{
	if (str[ptr->j] == '$' && str[ptr->j + 1] != ' ' && str[ptr->j + 1] != 0 \
	&& str[ptr->j + 1] != '$' && str[ptr->j + 1] != 34)
		return (0);
	return (1);
}

int	check_variable(t_data *ptr, char *str)
{
	ptr->j = ptr->vstart;
	while (str[ptr->j] != 0)
	{
		while (ft_checker(ptr, str) == 0)
			ptr->j++;
		if (str[ptr->j] == 34)
			ptr->qflag = ptr->qflag + 1;
		if (str[ptr->j] != 0)
		{
			if (str[ptr->j] == 39 && ptr->qflag % 2 == 0)
				ptr->j = ft_skip(str, ptr->j + 1, 39);
			if (ft_check(ptr, str) == 0)
			{
				ptr->vstart = ptr->j;
				ptr->j++;
				while (str[ptr->j] != ' ' && str[ptr->j] != 34 \
				&& str[ptr->j] != 0 && str[ptr->j] != '$' && str[ptr->j] != 39)
					ptr->j++;
				ptr->vlength = ptr->j - ptr->vstart;
				return (1);
			}
			ptr->j++;
		}
	}
	return (0);
}

char	*var_expander(t_data *ptr, char *str)
{
	char	*variable;
	char	*first;
	char	*rest;
	char	*new;

	ft_init(ptr);
	while (check_variable(ptr, str) != 0)
	{
		first = ft_substr(str, 0, ptr->vstart);
		variable = ft_substr(str, ptr->vstart + 1, ptr->vlength -1);
		rest = ft_substr(str, ptr->vlength + ptr->vstart, \
		ft_strlen(str) - ptr->vlength - ptr->vstart);
		if (search_list(ptr->lst_var, variable) != 0)
		{
			new = ft_strjoin_three(first, search_list(ptr->lst_var, variable), \
			rest);
		}
		else
			new = ft_strjoin(first, rest);
		free(str);
		str = ft_strdup(new);
		str_free(first, variable, rest, new);
	}
	return (str);
}
