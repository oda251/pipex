/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:39:49 by yoda              #+#    #+#             */
/*   Updated: 2023/11/05 22:23:08 by yoda             ###   ########.fr       */
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

typedef struct s_cmd
{
	char	*row_cmd;
	char	**argv;
	char	in_fd;
	char	out_fd;
}	t_cmd;
typedef struct s_pipex
{
	bool	heredoc_flag;
	int		cmd_size;
	char	**argv;
	char	**envp;
	pid_t	*pid;
	int		*pipe;
}	t_pipex;
void	ini_pipex(t_pipex *p, char **envp);
void	pipex(t_pipex p, int fd, int count);
void	ft_perror(char *arg);
void	perror_exit(t_pipex *p, char *arg, int free_flag);
void	error_invalid_usage(void);
void	error_cmd_not_found(char *cmd, t_pipex *p);
void	ft_close(int *fd);
void	free_pipex(t_pipex *p);

#endif