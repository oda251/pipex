/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:39:49 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 19:49:18 by yoda             ###   ########.fr       */
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
	int		cmd_size;
	char	**envp;
	int		infile;
	int		outfile;
}	t_pipex;
void	ini_pipex(t_pipex *p, char **envp);
void	has_here_doc(int *c, char ***v, t_pipex *p);
int		arg_check_files(int c, char **v, t_pipex *p);
void	arg_check_cmds(t_pipex *p);
char	***trans_args(int c, char **v);
void	pipex(t_pipex p, int fd, int count);
void	ft_perror(char *arg);
void	perror_exit(t_pipex *p, char *arg, int free_flag);
void	error_invalid_usage(void);
void	error_cmd_not_found(char *cmd, t_pipex *p);
void	ft_close(int *fd);
void	free_pipex(t_pipex *p);

#endif