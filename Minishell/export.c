/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:27:01 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/11/12 15:20:48 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_export(t_env *exp)
{
	t_env	*temp1;
	t_env	*temp2;
	int		i;

	i = 1;
	temp2 = NULL;
	if (exp == NULL)
		return ;
	while (i)
	{
		i = 0;
		temp1 = exp;
		while (temp1->next != temp2)
		{
			if (ft_strcmp(temp1->var[0], temp1->next->var[0]) > 0)
			{
				swap_list(temp1, temp1->next);
				i = 1;
			}
			temp1 = temp1->next;
		}
		temp2 = temp1;
	}
}

void	print_export(t_data *ptr)
{
	t_env	*temp;

	temp = ptr->lst_export;
	sort_export(temp);
	while (temp != NULL)
	{
		if (ft_strcmp(temp->var[0], "SHLVL") == 0)
		{
			if (ft_strcmp(temp->var[1], "0") == 0)
			{
				ft_putstr_fd("declare -x ", 1);
				ft_print(temp->var[0], "=", temp->var[1], 1);
				temp = temp->next;
			}
		}
		ft_putstr_fd("declare -x ", 1);
		ft_print(temp->var[0], "=", temp->var[1], 1);
		write(1, "\n", 1);
		temp = temp->next;
	}
	free (temp);
}

void	change_variable(t_env *list, char *s1, char *s2)
{
	t_env	*l;

	l = list;
	while (list != NULL)
	{
		if (ft_strcmp(s1, list->var[0]) == 0)
		{
			free(list->var[1]);
			list->var[1] = ft_strdup(s2);
			if (!list->var[1])
				return ;
			list = l;
			break ;
		}
		list = list->next;
	}
	list = l;
}

static void	ft_export_parser(t_data *ptr)
{
	char	**split;
	int		i;

	i = 1;
	while (ptr->split_arv[i] != 0)
	{
		split = env_split(ptr->split_arv[i]);
		if (ft_strchr(ptr->split_arv[i], '=') != 0 && \
		search_list(ptr->lst_var, split[0]) == 0)
			i = insert_new_node(ptr, split, i);
		else if (search_list(ptr->lst_export, split[0]) != 0)
			i = change_variable_value(ptr, split, i);
		else if (search_list(ptr->lst_var, ptr->split_arv[i]) != 0)
			export_variable(ptr, ptr->split_arv[i]);
		i++;
		free_array(split);
	}
}

void	ft_export(t_data *ptr)
{
	change_variable(ptr->lst_var, "?", "0");
	if (ft_sizeofarray(ptr->arv) == 1)
		print_export(ptr);
	else if (ft_isalpha(ptr->split_arv[1][0]) != 1)
	{
		ft_putstr_fd("Minishell: export : not a valid identifier\n", 2);
		change_variable(ptr->lst_var, "?", "1");
		return ;
	}
	else
		ft_export_parser(ptr);
}
