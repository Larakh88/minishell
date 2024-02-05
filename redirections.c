/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:20:08 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/12 14:20:11 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	count_redirections(t_data *ptr)
{
	int	j;

	ptr->flag = 0;
	ptr->rcount = 0;
	ptr->rcount1 = 0;
	ptr->hdcount = 0;
	ptr->flag = 0;
	j = ptr->k;
	while (ft_strcmp(ptr->pr[j], "|") != 0 && ptr->pr[j] != NULL)
	{
		if (ft_strcmp(ptr->pr[j], ">") == 0 || ft_strcmp(ptr->pr[j], ">>") == 0)
			ptr->rcount++;
		if (ft_strcmp(ptr->pr[j], "<") == 0)
		{
			ptr->rcount1++;
			if (j == ptr->k)
				ptr->flag = 1;
		}
		if (ft_strcmp(ptr->pr[j], "<<") == 0)
			ptr->hdcount++;
		j++;
	}
}

static void	out_redirections(t_data *ptr, int j)
{
	int	file;

	j = ptr->k;
	while (ptr->rcount > 0)
	{
		if (ft_strcmp(ptr->pr[j], ">") == 0)
			file = open (ptr->split_pr[++ptr->k], O_WRONLY | O_CREAT | O_TRUNC, \
			0644);
		else if (ft_strcmp(ptr->pr[j], ">>") == 0)
			file = open(ptr->split_pr[++ptr->k], O_WRONLY | O_CREAT | O_APPEND, \
			0644);
		if (file == -1)
		{
			ft_free_pipes(ptr);
			ft_putstr_fd("Minishell: syntax error\n", 2);
			exit (1);
		}
		ptr->rcount--;
		j++;
		if (ptr->rcount == 0)
		{
			dup2(file, STDOUT_FILENO);
			close(file);
		}
	}
}

static void	in_redirections(t_data *ptr)
{
	int	file1;

	while (ptr->rcount1 > 0)
	{
		ptr->rcount1--;
		if (ptr->rcount1 == 0)
		{
			file1 = open (ptr->split_pr[++ptr->k], O_RDONLY);
			if (file1 == -1)
			{
				ft_free_pipes(ptr);
				ft_putstr_fd("Minishell: syntax error\n", 2);
				exit (1);
			}
			dup2(file1, STDIN_FILENO);
			close(file1);
		}
	}
}

void	ft_redirections(t_data *ptr, int i)
{
	count_redirections(ptr);
	if (ptr->hdcount > 0)
		heredoc(ptr);
	if (ptr->rcount == 0)
	{
		if (i != ptr->pcount)
		{
			dup2(ptr->fd[i][1], STDOUT_FILENO);
			close(ptr->fd[i][1]);
		}
		if (ptr->rcount1 == 0)
			return ;
	}
	if (ptr->flag == 1)
	{
		in_redirections(ptr);
		out_redirections(ptr, 0);
	}
	else
	{
		out_redirections(ptr, 0);
		in_redirections(ptr);
	}
}
