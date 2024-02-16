/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:24:29 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/11/02 23:46:54 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	list_len(t_env *lst)
{
	int		i;
	t_env	*temp;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

char	**convert_to_arr(t_env *lst)
{
	int		i;
	int		len;
	t_env	*temp;
	char	*str;
	char	**arr;

	len = list_len(lst);
	i = 0;
	temp = lst;
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	while (temp != NULL)
	{
		str = ft_strjoin(temp->var[0], "=");
		arr[i] = ft_strjoin(str, temp->var[1]);
		i++;
		free(str);
		temp = temp->next;
	}
	arr[i] = NULL;
	return (arr);
}
