/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:58:24 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/11/02 23:48:52 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shlvl_plus(t_data *ptr)
{
	int		a;
	char	*b;

	a = ft_atoi(search_list(ptr->lst_export, "SHLVL"));
	a++;
	b = ft_itoa(a);
	change_variable(ptr->lst_export, "SHLVL", b);
	change_variable(ptr->lst_envp, "SHLVL", b);
	change_variable(ptr->lst_var, "SHLVL", b);
	free (b);
}

void	ft_shlvl(t_data *ptr)
{
	if (search_list(ptr->lst_export, "SHLVL") == 0)
		return ;
	if (ft_strcmp(search_list(ptr->lst_export, "SHLVL"), "0") != 0)
	{
		if (ft_atoi(search_list(ptr->lst_export, "SHLVL")) >= 999)
		{
			change_variable(ptr->lst_export, "SHLVL", "0");
			change_variable(ptr->lst_envp, "SHLVL", "0");
			change_variable(ptr->lst_var, "SHLVL", "\0");
		}
		else
			ft_shlvl_plus(ptr);
	}
	else
	{
		change_variable(ptr->lst_envp, "SHLVL", "1");
		change_variable(ptr->lst_export, "SHLVL", "1");
		change_variable(ptr->lst_var, "SHLVL", "1");
	}
}
