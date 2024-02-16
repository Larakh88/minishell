/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:44:56 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/12 14:08:00 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_len(char *s, t_data *ptr, int j)
{
	int	i;

	i = 0;
	while (s[i] != 0 && s[i] != '|' && s[i] != '>' && s[i] != '<')
	{
		if (s[i] == 39)
			i = ft_skip(s, i + 1, 39);
		if (s[i] == 34)
			i = ft_skip(s, i + 1, 34);
		i++;
	}
	if (j < ptr->prcount)
	{
		ptr->prlen = i;
		while (s[ptr->prlen] == '|' || s[ptr->prlen] == '>' \
		|| s[ptr->prlen] == '<')
			ptr->prlen++;
		ptr->pr[j] = ft_substr(s, i, ptr->prlen - i);
	}
	if (i == 0)
		return (0);
	while (s[i - 1] == ' ')
		i--;
	return (i);
}

static int	ft_start(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' && s[i] != 0)
		i++;
	return (i);
}

static void	pipe_count(t_data *ptr)
{
	int	i;

	i = 0;
	ptr->pcount = 0;
	while (ptr->pr[i] != 0)
	{
		if (ptr->pr[i][0] == 124)
			ptr->pcount++;
		i++;
	}
}

void	split_pipes_redirections(t_data *ptr)
{
	int		j;
	int		len;
	char	*d;
	int		start;

	j = 0;
	start = 0;
	len = 0;
	d = ptr->s;
	ptr->prlen = 0;
	ptr->split_pr = (char **)malloc(sizeof(char *) * (ptr->prcount + 2));
	ptr->pr = (char **)malloc(sizeof(char *) * (ptr->prcount + 1));
	if (!ptr->split_pr)
		return ;
	while (j <= ptr->prcount)
	{
		start = ft_start(d);
		len = ft_len(d + start, ptr, j);
		ptr->split_pr[j] = ft_substr(d, start, len);
		d = d + ptr->prlen + start;
		j++;
	}
	ptr->pr[j - 1] = NULL;
	ptr->split_pr[j] = NULL;
	pipe_count(ptr);
}
