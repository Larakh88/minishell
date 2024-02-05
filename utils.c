/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:55:29 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/12 10:59:46 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_sizeofarray(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	**ft_arrdup(char **s1)
{
	char	**dest;
	int		size;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	size = ft_sizeofarray(s1);
	dest = (char **)ft_calloc(sizeof (char *), size + 1);
	if (dest == 0)
		return (0);
	while (s1[i] != 0)
	{
		dest[i] = ft_strdup(s1[i]);
		i++;
	}
	return (dest);
}

void	ft_initialize(t_data *ptr, char **envp)
{
	int			n;

	ptr->vlength = 0;
	ptr->vstart = 0;
	ptr->i = 0;
	ptr->prcount = 0;
	ptr->dq = 0;
	ptr->sq = 0;
	n = ft_sizeofarray(envp);
	ptr->lst_envp = create_list(envp, n);
	ptr->lst_export = create_list(envp, n);
	unset_var(&ptr->lst_export, "_");
	ptr->lst_var = create_list(envp, n);
	insert_node(&ptr->lst_var, "?=0");
	ft_shlvl(ptr);
}

int	check_digit(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] != 0)
	{
		if (ft_isdigit(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_print(char *s1, char *s2, char *s3, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(s2, fd);
	ft_putstr_fd(s3, fd);
}
