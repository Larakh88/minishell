/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:37:30 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/07 14:21:48 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_pipes(t_data *ptr)
{
	free_array(ptr->pr);
	free_array(ptr->split_pr);
	free(ptr->s);
	free_array(ptr->arv);
	free_array(ptr->split_arv);
	free(ptr->pid1);
	free_fd(ptr, ptr->fd);
	delete(ptr->lst_envp);
	delete(ptr->lst_export);
	delete(ptr->lst_var);
	free(ptr);
}

void	ft_free_single(t_data *ptr)
{
	if (ft_strcmp(ptr->arv[0], "./minishell") != 0)
		free_array(ptr->split_arv);
	free_array(ptr->arv);
	free(ptr->s);
}

void	ft_free_exit(t_data *ptr)
{
	delete(ptr->lst_envp);
	delete(ptr->lst_export);
	delete(ptr->lst_var);
	free_array(ptr->split_arv);
	free_array(ptr->arv);
	free(ptr->s);
	free(ptr);
}

void	ft_free_externals(t_data *ptr)
{
	free_array(ptr->split_arv);
	free_array(ptr->arv);
	free_array(ptr->env);
	delete(ptr->lst_envp);
	delete(ptr->lst_export);
	delete(ptr->lst_var);
	free(ptr->path);
	free(ptr->s);
	free(ptr);
}

void	ft_free_init(t_data *ptr)
{
	delete(ptr->lst_envp);
	delete(ptr->lst_export);
	delete(ptr->lst_var);
	free(ptr);
}
