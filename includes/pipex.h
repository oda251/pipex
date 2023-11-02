/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:39:49 by yoda              #+#    #+#             */
/*   Updated: 2023/11/02 06:30:31 by yoda             ###   ########.fr       */
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

char	***trans_args(int c, char **v, char *str);
char	*read_till_limiter(int fd, char *limiter);
void	perror_exit(int *fd_lst, char *arg, int free_flag);
void	perror_free_args_exit(int *fd_lst, char ***args);
void	invalid_usage(void);
void	cmd_not_found(char *cmd);
void	ft_close(int *fd);
void	ft_close_all(int *fd_lst);
void	free_args(char ***args);
int		ft_dup_fds(int *fd_lst, int stdin, int stdout);

#endif