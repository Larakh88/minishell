/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:36:45 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/04 08:39:44 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free (str);
		str = NULL;
	}
}

void	str_free(char *s1, char *s2, char *s3, char *s4)
{
	free(s1);
	free(s2);
	free(s3);
	free(s4);
}

void	free_node(t_env *temp)
{
	if (temp)
	{
		free_array(temp->var);
		free (temp);
	}
	temp = NULL;
}

void	delete(t_env *list)
{
	t_env	*t1;

	while (list != NULL)
	{
		t1 = list;
		list = list->next;
		free_array(t1->var);
		t1->var = NULL;
		free(t1);
		t1 = NULL;
	}
	free (list);
}

void	free_fd(t_data *ptr, int **nb)
{
	int	i;

	i = 0;
	if (nb)
	{
		while (i < ptr->pcount)
		{
			free(nb[i]);
			i++;
		}
		free (nb);
	}
}
