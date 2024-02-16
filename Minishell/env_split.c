/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:28:06 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/12 14:58:21 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != 0)
		i++;
	return (i);
}

char	**env_split(char *str)
{
	char	**split;
	size_t	end;
	int		len;

	end = ft_end(str);
	if (end + 1 == ft_strlen(str))
	{
		split = (char **)malloc(sizeof(char *) * 2);
		split[0] = ft_substr(str, 0, end);
		split[1] = NULL;
	}
	else
	{
		split = (char **)malloc(sizeof(char *) * 3);
		split[0] = ft_substr(str, 0, end);
		len = ft_strlen(str) - end - 1;
		split[1] = ft_substr(str, end + 1, len);
		split[2] = NULL;
	}
	return (split);
}

static void	unset_var1(t_env *temp, t_env *prev, t_env **lst)
{
	if (temp != NULL)
	{
		if (temp == *lst)
		{
			*lst = (*lst)->next;
			free_array(temp->var);
			free(temp);
		}
		else
		{
			free_array(temp->var);
			prev->next = temp->next;
			free(temp);
		}
	}
}

void	unset_var(t_env **lst, char *str)
{
	t_env	*temp;
	t_env	*prev;

	temp = *lst;
	if (search_list(temp, str) == 0)
		return ;
	while (temp->next != NULL)
	{
		if (ft_strcmp(temp->var[0], str) == 0)
			break ;
		prev = temp;
		temp = temp->next;
	}
	unset_var1(temp, prev, lst);
}

void	ft_set_(t_data *ptr)
{
	int	i;

	i = ft_sizeofarray(ptr->split_arv) - 1;
	if (ptr->arv[0] == NULL || ptr->split_arv[0] == NULL)
		return ;
	change_variable(ptr->lst_var, "_", ptr->split_arv[i]);
	change_variable(ptr->lst_envp, "_", "/usr/bin/env");
}
