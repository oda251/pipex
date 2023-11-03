/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:39:49 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 16:22:49 by yoda             ###   ########.fr       */
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
	int		arg_count;
	char	**envp;
	int		infile;
	int		outfile;
}	t_pipex;
int		arg_check_files(int c, char **v, int here_doc);
void	arg_check_cmds(char **envp, t_pipex p);
char	***trans_args(int c, char **v);
void	pipex(t_pipex p, int fd, int count);
void	ft_perror(char *arg);
void	perror_exit(t_pipex *p, char *arg, int free_flag);
void	error_invalid_usage(void);
void	error_cmd_not_found(char *cmd);
void	ft_close(int *fd);
void	ft_close_all(int *fd_lst);
void	free_args(char ***args);
int		ft_dup_fds(int *fd_lst, int stdin, int stdout);
void	free_char_double_p(char **arg);
void	free_pipex(t_pipex *p);

#endif