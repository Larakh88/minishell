/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:52:48 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/08 19:58:30 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_pipe(t_data *ptr, int i)
{
	int	pipe;
	int	l;

	pipe = 0;
	l = 0;
	if (i == 0)
		return (0);
	while (ptr->pr[l] != 0 && pipe < i)
	{
		if (ft_strcmp(ptr->pr[l], "|") == 0)
			pipe++;
		l++;
	}
	return (l);
}

static void	pipe_exit_code(t_data *ptr, int i)
{
	int		status;
	char	*temp;

	waitpid (ptr->pid1[i], &status, 0);
	if (WIFSIGNALED(status))
	{
		temp = ft_itoa(WIFSIGNALED(status));
		change_variable(ptr->lst_var, "?", temp);
		free(temp);
	}
	else
	{
		temp = ft_itoa(WEXITSTATUS(status));
		change_variable(ptr->lst_var, "?", temp);
		free(temp);
	}
}

void	ft_wait_close(t_data *ptr)
{
	int		i;

	i = 0;
	while (i < ptr->pcount)
	{
		close(ptr->fd[i][0]);
		close(ptr->fd[i][1]);
		i++;
	}
	i = 0;
	while (i <= ptr->pcount)
	{
		pipe_exit_code(ptr, i);
		i++;
	}
}
