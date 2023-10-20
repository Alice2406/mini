/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:54:09 by jmorvan           #+#    #+#             */
/*   Updated: 2023/06/26 16:47:23 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/* a supprimer avant le final push, la moulinette n'aime pas
(sert a annuler une error vscode avec la struct sigaction). ¯\_(ツ)_/¯ */
#	define _XOPEN_SOURCE 700 

# include	"../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
#	include <errno.h>

# define PIPE 1
# define OUTFILE 2
# define D_OUTFILE 3
# define INFILE 4
# define HERE_DOC 5
# define CMD 6

# define WEXE ": command not found\n"
# define WPERM ": Permission denied\n"
# define WFILENAME ": No such file or directory\n"
# define WUNQUOTE "Error : Unclosed quote !\n"
# define WREDIR "syntax error near unexpected token\n"
# define ALLOC_ERR "Memory allocation error !\n"

extern unsigned char	g_value;

typedef struct s_garbage
{
	void				*alloc;
	int					id;
	struct s_garbage	*last;
	struct s_garbage	*next;
}	t_garbage;

typedef struct s_token
{
	unsigned char		type;
	char				**arg;
	struct s_token	*right;
	struct s_token	*down;
}	t_token;

typedef struct s_minishell
{
	struct sigaction	ctrl_bs;
	struct sigaction	old_ctrl_c;
	struct sigaction	ctrl_c;
	t_token				*root;
	t_garbage			*gc;
	char				***here_doc;
	char				*line;
	char				**env;
	int					old_pipe[2];
	int					pipe[2];
	int					error;
}	t_shell;

// signal.c
int		handle_signal(t_shell *shell, int s);
int		ignore_signal(t_shell *shell);
int		default_signal(t_shell *shell);

// new_env.c
int		create_env(t_shell *shell, char **env);

// execution.c
int		execution(t_shell *shell);
void	tree_branch(t_shell *shell, t_token *token);
int		wait_child(int pid);

// exe_utils.c
int		handle_cmd(t_shell *shell, t_token *token);
int		handle_heredoc(t_shell *shell, t_token *token);
int		handle_infile(t_token *token);
int		handle_outfile(t_token *token);

// exe_utils2.c
int		cmd_buildin(t_token	*token, int type);
void	handle_buildin(t_shell *shell, t_token *token);
int		check_name(char *exe);

// path_split.c
char	**get_path(t_shell *shell, char *exe);

// utlis.c
void	quit(t_shell *shell);

// exe_pipe.c
int	exe_pipe(t_shell *shell);

// garbage_collector.c
void	*gc_malloc(size_t size, t_garbage **collector, int id);
char	*ft_strdup_gc(const char *s, t_garbage **gc, int id);
void	clean_gc(t_garbage **collector, int id);
void	free_in_gc(t_garbage **gc, void *addr);

// error_msg.c
int		error_msg(char *msg, int status);
int		error_joinmsg(char *name, char *msg, int status);
int		perror_msg(char *str, int error);

// env_var.c
int		get_env_var_l(t_shell *shell, int *i, int quote);

int		parsing(t_shell *shell);

// void	print_env(char **env);
// void	show_gc(t_garbage *gc);

#endif