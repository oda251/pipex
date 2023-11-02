/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:16:12 by yoda              #+#    #+#             */
/*   Updated: 2023/11/02 02:05:21 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(int *fd_lst, char *arg, int free_flag)
{
	ft_close_all(fd_lst);
	ft_puterror("pipex: ");
	ft_puterror(ft_strtolower(strerror(errno)));
	if (arg)
	{
		ft_puterror(": ");
		ft_puterror(arg);
	}
	ft_puterror("\n");
	if (free_flag)
		free(arg);
	exit(EXIT_FAILURE);
}

void	perror_free_args_exit(int *fd_lst, char ***args)
{
	free_args(args);
	perror_exit(fd_lst, NULL, 0);
}

void	invalid_usage(void)
{
	ft_puterror("pipex: invalid argument\n");
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char *cmd)
{
	ft_puterror("pipex: command not found: ");
	ft_puterror(cmd);
	ft_puterror("\n");
	exit(EXIT_FAILURE);
}
