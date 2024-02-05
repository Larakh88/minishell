/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:23:43 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/02 17:41:10 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	skip(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0 && str[i] == ' ')
		i++;
	return (i);
}

static int	count_space(t_data *ptr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ptr->arv[i] != NULL)
	{
		if (skip(ptr->arv[i]) != ft_strlen(ptr->arv[i]))
			count++;
		i++;
	}
	return (count);
}

void	ft_remove_space(t_data *ptr)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = count_space(ptr);
	ptr->split_arv = (char **)malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		while (skip(ptr->arv[j]) == ft_strlen(ptr->arv[j]) \
		&& ptr->arv[j] != NULL)
			j++;
		ptr->split_arv[i] = ft_strdup(ptr->arv[j]);
			i++;
		j++;
	}
	ptr->split_arv[i] = NULL;
}
