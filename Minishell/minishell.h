/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:27:43 by lel-khou          #+#    #+#             */
/*   Updated: 2024/02/16 12:07:50 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <signal.h>
# include <fcntl.h>

extern int	g_sig;

typedef struct s_env
{
	char			**var;
	struct s_env	*next;
}				t_env;

typedef struct s_data
{
	char	*s;
	char	**arv;
	char	**env;
	char	**split_arv;
	char	*path;
	char	**split_path;
	char	**split_pr;
	char	**pr;
	char	cwd[256];
	int		prlen;
	int		**fd;
	int		i;
	int		j;
	int		k;
	int		prcount;
	int		pcount;
	int		rcount;
	int		rcount1;
	int		hdcount;
	int		vstart;
	int		vlength;
	int		flag;
	int		qflag;
	int		e_flag;
	int		dq;
	int		sq;
	int		exit;
	pid_t	pid;
	pid_t	*pid1;
	t_env	*lst_envp;
	t_env	*lst_export;
	t_env	*lst_var;
	t_env	*temp;
}	t_data;

void	check_commands(t_data *ptr);
int		check_variable(t_data *ptr, char *str);
char	*var_expander(t_data *ptr, char *str);
int		single_parse(t_data *ptr);
char	**ft_split_single(t_data *ptr);
void	ft_remove_space(t_data *ptr);
void	single_command(t_data *ptr);
void	ft_pipe(t_data *ptr);
void	split_pipes_redirections(t_data *ptr);
void	ft_redirections(t_data *ptr, int i);

//-----------------------------COMMANDS---------------------------------------//

void	ft_echo(char **s, t_data *ptr);
void	ft_cd_main(t_data *ptr);
int		ft_externals(t_data *ptr);
void	print_env(t_data *ptr);
void	ft_exit(t_data *ptr);

//-----------------------------EXPORT-----------------------------------------//

void	ft_export(t_data *ptr);
void	change_variable(t_env *list, char *s1, char *s2);
void	sort_export(t_env *exp);
void	print_export(t_data *ptr);
void	swap_list(t_env *a, t_env *b);
int		insert_new_node(t_data *ptr, char **split, int i);
int		change_variable_value(t_data *ptr, char **split, int i);
void	export_variable(t_data *ptr, char *split);
void	add_variable(t_data *ptr);

//-----------------------------UTILS-----------------------------------------//

int		ft_sizeofarray(char **s);
char	**ft_arrdup(char **s1);
void	ft_initialize(t_data *ptr, char **envp);
void	free_array(char **str);
void	str_free(char *s1, char *s2, char *s3, char *s4);
int		check_path(t_data *ptr);
void	free_node(t_env *temp);
void	free_fd(t_data *ptr, int **nb);
void	ft_free_pipes(t_data *ptr);
void	ft_free_single(t_data *ptr);
void	ft_free_exit(t_data *ptr);
void	ft_free_externals(t_data *ptr);
void	ft_free_init(t_data *ptr);
int		check_digit(char *s);
void	ft_print(char *s1, char *s2, char *s3, int fd);
int		ft_checker(t_data *ptr, char *str);

//-----------------------------SIGNALS----------------------------------------//

int		sig_count(int status);
void	sighandler(int signum);

//-----------------------------SPLIT UTILS------------------------------------//

int		ft_skip(char *s, int i, char c);
char	*dup_dquotes(t_data *ptr);
char	*dup_squotes(t_data *ptr);
char	*dup_word(t_data *ptr);
int		skip_space(t_data *ptr);

//-----------------------------PIPES UTILS-----------------------------------//

int		find_pipe(t_data *ptr, int i);
void	ft_wait_close(t_data *ptr);
void	heredoc(t_data *ptr);

//-----------------------------LIST------------------------------------------//

char	**env_split(char *str);
void	insert_node(t_env **node, char *str);
t_env	*create_list(char **env, int n);
char	*search_list(t_env *list, char *str);
void	unset_var(t_env **lst, char *str);
void	ft_unset(t_data *ptr);
char	**convert_to_arr(t_env *lst);
void	delete(t_env *list);
void	ft_set_(t_data *ptr);

//-----------------------------SHLVL-----------------------------------------//

void	ft_shlvl_plus(t_data *ptr);
void	ft_shlvl(t_data *ptr);

#endif
