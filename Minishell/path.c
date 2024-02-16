/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:01:48 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/12 13:06:41 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	path_verif(t_data *ptr, struct dirent *direntp, DIR *dirp, int i)
{
	char	*temp;

	while (direntp != NULL)
	{
		if (ft_strcmp(direntp->d_name, ptr->split_arv[0]) == 0)
		{
			temp = ft_strjoin("/", ptr->split_arv[0]);
			ptr->path = ft_strjoin(ptr->split_path[i], temp);
			closedir(dirp);
			free(temp);
			return (0);
		}
		direntp = readdir(dirp);
	}
	return (1);
}

static int	ft_path(t_data *ptr, int i)
{
	DIR				*dirp;
	struct dirent	*direntp;

	dirp = opendir(ptr->split_path[i]);
	if (dirp == NULL)
	{
		ft_putstr_fd("File could not be opened\n", 2);
		return (1);
	}
	direntp = readdir(dirp);
	if (path_verif(ptr, direntp, dirp, i) == 0)
	{
		free_array(ptr->split_path);
		return (2);
	}
	closedir(dirp);
	return (0);
}

int	check_path(t_data *ptr)
{
	int				i;

	ptr->split_path = ft_split(search_list(ptr->lst_var, "PATH"), ':');
	if (!ptr->split_path)
		return (1);
	i = 0;
	while (ptr->split_path[i] != NULL)
	{
		if (ft_path(ptr, i) == 2)
			return (0);
		if (ft_path(ptr, i) == 1)
			return (1);
		i++;
	}
	free_array(ptr->split_path);
	return (1);
}
