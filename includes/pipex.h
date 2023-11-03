/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:39:49 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 21:25:59 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# define NONE -1
# define TRUE 1
# define FALSE 0
# define SUCCESS "Success"

typedef struct s_pipex
{
	int		here_doc;
	char	***args;
	int		arg_size;
	int		cmd_size;
	char	**envp;
	int		infile;
	int		outfile;
	pid_t	*pid;
	int		*fd;
}	t_pipex;
void	ini_pipex(t_pipex *p, char **envp);
void	has_here_doc(int *c, char ***v, t_pipex *p);
int		arg_check_files(int c, char **v, int here_doc);
void	arg_check_cmds(char **envp, t_pipex p);
char	***trans_args(int c, char **v);
void	pipex(t_pipex *p);
void	ft_perror(char *arg);
void	perror_exit(t_pipex *p, char *arg, int free_flag);
void	error_invalid_usage(void);
void	error_cmd_not_found(char *cmd);
void	ft_close(int *fd);
int		ft_dup_fds(int *fd_lst, int stdin, int stdout);
void	free_pipex(t_pipex *p);

#endif