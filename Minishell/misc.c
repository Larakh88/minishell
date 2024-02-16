/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:47:31 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/11/12 15:01:04 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sig_count(int status)
{
	static int	child;

	if (status == 1)
		child = 1;
	if (status == 2)
		child = 0;
	if (child == 1)
		return (0);
	return (1);
}

int	ft_checker(t_data *ptr, char *str)
{
	if (str[ptr->j] != '$' && str[ptr->j] != 34 && \
		str[ptr->j] != 39 && str[ptr->j] != 0)
		return (0);
	return (1);
}

void	swap_list(t_env *a, t_env *b)
{
	char	**temp;

	temp = a->var;
	a->var = b->var;
	b->var = temp;
}
