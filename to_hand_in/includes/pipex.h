/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:39:49 by yoda              #+#    #+#             */
/*   Updated: 2023/11/06 04:09:46 by yoda             ###   ########.fr       */
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
# include <stdbool.h>
# include "libft.h"
# define NONE -1
# define SUCCESS "Success"
# define SPACE " \n\t\v\f\r"
# define TMP_PATH "/tmp/pipex_tmp"

typedef struct s_cmd
{
	char	*row_cmd;
	char	**argv;
}	t_cmd;
typedef struct s_pipex
{
	bool	heredoc_flag;
	int		cmd_size;
	char	**argv;
	char	**envp;
	pid_t	*pid;
	char	**paths;
	char	*tmp_path;
}	t_pipex;
void	init_pipex(t_pipex *p, int argc, char **argv, char **envp);
char	*prepare_tmpfile(t_pipex *p);
void	execute_cmds(t_pipex p);
t_cmd	parse_cmd(t_pipex *p, int index);
void	ft_perror(char *arg, bool former_flag);
void	perror_exit(t_pipex *p, char *arg, bool former_flag);
void	error_invalid_usage(void);
void	error_cmd_not_found(char *cmd, t_pipex *p);
void	ft_close(int *fd);
void	free_pipex(t_pipex *p);

#endif