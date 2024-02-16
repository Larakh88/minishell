/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:27:45 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/11/12 12:15:55 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_delimiter(t_data *ptr)
{
	int		j;
	int		i;
	char	**delimiter;

	j = ptr->hdcount;
	i = 0;
	delimiter = (char **)malloc(sizeof(char *) * (ptr->hdcount + 1));
	while (j > 0)
	{
		delimiter[i] = ft_strdup(ptr->split_pr[++ptr->k]);
		i++;
		j--;
	}
	delimiter[i] = NULL;
	return (delimiter);
}

static char	*ft_skip_delim(char *line, char *delimiter)
{
	while (ft_strcmp(line, delimiter) != 0)
	{
		if (line == NULL)
			exit (0);
		line = readline("> ");
	}
	return (line);
}

static int	ft_open(char **delimiter, char *line, int i)
{
	int	fd;

	fd = open("temp", O_CREAT, 0700);
	while (ft_strcmp(line, delimiter[i]) != 0)
	{
		if (line == NULL)
			exit(0);
		fd = open("temp", O_WRONLY | O_APPEND, 0700);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		line = readline("> ");
	}
	return (fd);
}

void	heredoc(t_data *ptr)
{
	char	**delimiter;
	char	*line;
	int		fd;
	int		i;

	delimiter = ft_delimiter(ptr);
	i = 0;
	line = readline("> ");
	while (i < ptr->hdcount - 1)
	{
		line = ft_skip_delim(line, delimiter[i]);
		if (ft_strcmp(line, delimiter[i]) == 0)
		{
			line = readline("> ");
			i++;
		}
	}
	fd = ft_open(delimiter, line, i);
	close(fd);
	fd = open("temp", O_RDONLY, 0400);
	unlink("temp");
	dup2(fd, STDIN_FILENO);
	close (fd);
	free_array(delimiter);
	free(line);
}
