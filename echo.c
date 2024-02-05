/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:56:40 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/11/12 10:59:43 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	skip_n(char **s, t_data *ptr, int j, int k)
{
	int	len;

	while (s[k] != NULL && s[k][0] == '-' && s[k][1] != '\0')
	{	
		if (s[k][0] == '-')
		{	
			j = 1;
			while (s[k][j] != '\0' && s[k][j] == 'n')
			{
				ptr->e_flag = 1;
				j++;
			}
			len = ft_strlen(s[k]);
			if (j != len)
			{
				if (k == 1)
					ptr->e_flag = 0;
				return (k);
			}
		}
		k = k + 2;
	}
	return (k);
}

void	ft_echo(char **s, t_data *ptr)
{
	int	i;

	ptr->e_flag = 0;
	if (!s[1])
	{
		write(1, "\n", 1);
		change_variable(ptr->lst_var, "?", "0");
		return ;
	}
	i = skip_n(s, ptr, 1, 1);
	while (i < ft_sizeofarray(s))
	{
		ft_putstr_fd(s[i], 1);
		i++;
	}
	if (ptr->e_flag == 0)
		write(1, "\n", 1);
	change_variable(ptr->lst_var, "?", "0");
}
