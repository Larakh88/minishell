/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:13:32 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/12 15:20:49 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	insert_new_node(t_data *ptr, char **split, int i)
{
	char	*str;
	char	*temp;

	if (ft_sizeofarray(split) == 1)
		str = ft_strjoin(split[0], "=");
	else
	{
		temp = ft_strjoin(split[0], "=");
		str = ft_strjoin(temp, split[1]);
		free (temp);
	}
	insert_node(&ptr->lst_export, str);
	insert_node(&ptr->lst_envp, str);
	insert_node(&ptr->lst_var, str);
	free (str);
	return (i);
}

int	change_variable_value(t_data *ptr, char **split, int i)
{
	if (ft_sizeofarray(split) == 1)
	{
		change_variable(ptr->lst_envp, split[0], ptr->split_arv[i + 1]);
		change_variable(ptr->lst_export, split[0], ptr->split_arv[i + 1]);
		change_variable(ptr->lst_var, split[0], ptr->split_arv[i + 1]);
		i++;
	}
	else
	{
		change_variable(ptr->lst_envp, split[0], split[1]);
		change_variable(ptr->lst_export, split[0], split[1]);
		change_variable(ptr->lst_var, split[0], split[1]);
	}
	return (i);
}

void	export_variable(t_data *ptr, char *split)
{
	char	*s;
	char	*str;

	s = ft_strjoin(split, "=");
	str = ft_strjoin(s, search_list(ptr->lst_var, split));
	insert_node(&ptr->lst_envp, str);
	insert_node(&ptr->lst_export, str);
	free(str);
	free(s);
}

static int	change_local_variable(t_data *ptr, char **split, int i)
{
	if (ft_sizeofarray(split) == 2)
		change_variable(ptr->lst_var, split[0], split[1]);
	else
	{
		change_variable(ptr->lst_var, split[0], ptr->split_arv[i + 1]);
		i++;
	}
	return (i);
}

void	add_variable(t_data *ptr)
{
	int		i;
	char	**split;
	char	*str;

	i = 0;
	while (i < ft_sizeofarray(ptr->split_arv))
	{
		split = env_split(ptr->split_arv[i]);
		if (search_list(ptr->lst_var, split[0]) == 0)
		{
			if (ft_sizeofarray(split) == 2)
				insert_node(&ptr->lst_var, ptr->split_arv[i]);
			else
			{
				str = ft_strjoin(split[0], "= ");
				insert_node(&ptr->lst_var, str);
				free (str);
				i++;
			}
		}
		else
			i = change_local_variable(ptr, split, i);
		i++;
		free_array(split);
	}
}
