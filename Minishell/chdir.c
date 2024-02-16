/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:15:15 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/11 17:12:15 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_error(t_data *ptr, char *s, char *msg1, char *msg2)
{
	change_variable(ptr->lst_var, "?", "1");
	ft_print(msg1, ptr->split_arv[1], msg2, 2);
	free(s);
}

static int	cd_handler(t_data *ptr, char *s)
{
	char	*str;

	if (ptr->arv[1] == NULL || ft_strcmp(ptr->arv[1], "~") == 0)
	{
		ptr->i = chdir(s);
		return (0);
	}
	else if (ptr->arv[1][0] == '~')
	{
		str = ft_strjoin(s, (ptr->arv[1] + 1));
		ptr->i = chdir(str);
		free(str);
		return (0);
	}
	else
		ptr->i = chdir(ptr->arv[1]);
	if (ptr->i == -1)
	{
		ft_error(ptr, s, "Minishell: cd: ", ": No such file or directory\n");
		return (1);
	}
	return (0);
}

static int	ft_cd(t_data *ptr)
{
	char	*s;
	int		j;

	if (search_list(ptr->lst_var, "HOME") != 0)
		s = ft_strdup(search_list(ptr->lst_var, "HOME"));
	else
		s = ft_strdup("/Users/laraelkhoury");
	if (ptr->arv[1] == NULL && search_list(ptr->lst_var, "HOME") == 0)
	{
		ft_error(ptr, s, "Minishell: cd: ", "HOME not set\n");
		return (1);
	}
	j = cd_handler(ptr, s);
	if (j == 0)
	{
		free(s);
		return (0);
	}
	else
		return (1);
}

void	ft_cd_main(t_data *ptr)
{
	int	i;

	i = 0;
	change_variable(ptr->lst_var, "?", "0");
	if (ft_strcmp(ptr->split_arv[1], "-") == 0)
		chdir(search_list(ptr->lst_envp, "OLDPWD"));
	else
		i = ft_cd(ptr);
	if (i == 0)
	{
		getcwd(ptr->cwd, sizeof(ptr->cwd));
		change_variable(ptr->lst_envp, "OLDPWD", \
		search_list(ptr->lst_var, "PWD"));
		change_variable(ptr->lst_export, "OLDPWD", \
		search_list(ptr->lst_var, "PWD"));
		change_variable(ptr->lst_var, "OLDPWD", \
		search_list(ptr->lst_var, "PWD"));
		change_variable(ptr->lst_envp, "PWD", ptr->cwd);
		change_variable(ptr->lst_export, "PWD", ptr->cwd);
		change_variable(ptr->lst_var, "PWD", ptr->cwd);
	}
}
