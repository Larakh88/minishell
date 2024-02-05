/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:49:17 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/12 14:58:23 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_data *ptr)
{
	t_env	*temp;

	temp = ptr->lst_envp;
	change_variable(ptr->lst_var, "?", "0");
	while (temp != NULL)
	{
		if (ft_strcmp(temp->var[0], "SHLVL") == 0)
		{
			if (ft_strcmp(temp->var[1], "0") == 0)
			{
				ft_putstr_fd(temp->var[0], 1);
				write(1, "\n", 1);
				temp = temp->next;
			}
		}
		ft_print(temp->var[0], "=", temp->var[1], 1);
		write(1, "\n", 1);
		temp = temp->next;
	}
}

void	ft_exit(t_data *ptr)
{
	int	i;

	i = ft_atoi(search_list(ptr->lst_var, "?"));
	if (ft_sizeofarray(ptr->split_arv) > 2)
	{
		ft_putstr_fd("exit\nMinishell: exit: too many arguments\n", 2);
		change_variable(ptr->lst_var, "?", "1");
		i = 1;
		return ;
	}
	if (ptr->split_arv[1] != NULL && check_digit(ptr->split_arv[1]) == 0)
		i = ft_atoi(ptr->split_arv[1]);
	else if (ptr->split_arv[1] != NULL && check_digit(ptr->split_arv[1]) == 1)
	{
		ft_print("exit\nMinishell: exit: ", ptr->split_arv[1], \
		": numeric argument required\n", 2);
		i = 255;
		change_variable(ptr->lst_var, "?", "255");
	}
	ft_free_exit(ptr);
	exit (i);
}

static void	ft_parser(t_data *ptr)
{
	getcwd(ptr->cwd, sizeof(ptr->cwd));
	if (ft_strcmp(ptr->arv[0], "pwd") == 0)
	{
		ft_putstr_fd(ptr->cwd, 1);
		write(1, "\n", 1);
	}
	else if (ft_strcmp(ptr->arv[0], "cd") == 0)
		ft_cd_main(ptr);
	else if (ft_strcmp(ptr->arv[0], "env") == 0)
		print_env(ptr);
	else if (ft_strcmp(ptr->arv[0], "echo") == 0)
		ft_echo(ptr->arv, ptr);
	else if (ft_strcmp(ptr->arv[0], "exit") == 0)
		ft_exit(ptr);
	else if (ft_strcmp(ptr->arv[0], "unset") == 0)
		ft_unset(ptr);
	else if (ft_strcmp(ptr->arv[0], "export") == 0)
		ft_export(ptr);
	else if (ft_strchr(ptr->arv[0], '=') != 0)
		add_variable(ptr);
	else
		ft_externals(ptr);
}

int	single_parse(t_data *ptr)
{
	int	i;

	if (ptr->arv[0] == NULL)
		return (0);
	if (ptr->split_arv[0] == NULL)
	{
		ft_print("Minishell: ", ptr->arv[0], \
		": No such file or directory\n", 2);
		change_variable(ptr->lst_var, "?", "127");
		return (0);
	}
	ft_parser(ptr);
	i = ft_atoi(search_list(ptr->lst_var, "?"));
	return (i);
}
