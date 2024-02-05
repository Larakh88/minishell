/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:26:47 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/11/12 14:47:53 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_node(t_env **node, char *str)
{
	t_env	*temp;
	t_env	*ptr;

	temp = (t_env *)malloc(sizeof(t_env));
	temp->var = env_split(str);
	temp->next = NULL;
	if (*node == NULL)
		*node = temp;
	else
	{
		ptr = *node;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

t_env	*create_list(char **env, int n)
{
	t_env	*list;
	int		i;

	list = NULL;
	i = 0;
	while (i < n)
	{
		insert_node(&list, env[i]);
		i++;
	}
	return (list);
}

char	*search_list(t_env *list, char *str)
{
	t_env	*l;

	l = list;
	while (l != NULL)
	{
		if (ft_strcmp(str, l->var[0]) == 0)
		{
			return (l->var[1]);
		}
		l = l->next;
	}
	return (0);
}

void	ft_unset(t_data *ptr)
{
	int	i;

	i = 1;
	change_variable(ptr->lst_var, "?", "0");
	if (ptr->split_arv[i])
	{
		while (ptr->split_arv[i] != 0)
		{
			unset_var(&ptr->lst_envp, ptr->split_arv[i]);
			unset_var(&ptr->lst_export, ptr->split_arv[i]);
			unset_var(&ptr->lst_var, ptr->split_arv[i]);
			i++;
		}
	}
}
