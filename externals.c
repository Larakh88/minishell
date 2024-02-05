/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:44:50 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/11 17:12:10 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_exit(t_data *ptr)
{
	int		status;
	char	*temp;

	waitpid(ptr->pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		if (g_sig == 0)
			change_variable(ptr->lst_var, "?", "130");
		else if (g_sig == 2)
			change_variable(ptr->lst_var, "?", "131");
		g_sig = 0;
	}
	else if (WEXITSTATUS(status))
	{
		temp = ft_itoa(WEXITSTATUS(status));
		change_variable(ptr->lst_var, "?", temp);
		free(temp);
	}
}

static void	path_handler(t_data *ptr)
{
	char	*temp;

	ptr->path = ft_strdup(ptr->split_arv[0]);
	temp = ft_strtrim(ptr->split_arv[0], "./");
	if (ptr->split_arv[0][0] == '.')
	{
		free(ptr->split_arv[0]);
		ptr->split_arv[0] = ft_strdup(temp);
	}
	free(temp);
}

static void	ft_execve(t_data *ptr)
{
	ptr->env = convert_to_arr(ptr->lst_export);
	if (execve(ptr->path, ptr->split_arv, ptr->env) == -1)
	{	
		perror("Error");
		ft_free_externals(ptr);
		exit (127);
	}
}

static void	error_message(t_data *ptr)
{
	if (search_list(ptr->lst_var, "PATH") == 0)
		ft_print("Minishell: ", ptr->arv[0], \
		": No such file or directory\n", 2);
	else
		ft_print("Minishell: ", ptr->arv[0], ": command not found\n", 2);
}

int	ft_externals(t_data *ptr)
{
	change_variable(ptr->lst_var, "?", "0");
	if (ptr->split_arv[0][0] == '.' || ptr->split_arv[0][0] == '/')
		path_handler(ptr);
	else if (search_list(ptr->lst_var, "PATH") == 0 || check_path(ptr) == 1)
	{
		error_message(ptr);
		change_variable(ptr->lst_var, "?", "127");
		return (1);
	}
	ptr->pid = fork();
	if (ptr->pid == -1)
		return (-1);
	if (ptr->pid == 0)
		ft_execve(ptr);
	free(ptr->path);
	if (ptr->split_arv)
	{	
		free_array(ptr->split_arv);
		ptr->split_arv = NULL;
	}
	sig_count(1);
	wait_exit(ptr);
	sig_count(2);
	return (0);
}
