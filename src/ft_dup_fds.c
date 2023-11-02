/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:50:58 by yoda              #+#    #+#             */
/*   Updated: 2023/11/02 05:14:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_dup_fds(int *fd, int stdin, int stdout)
{
	fd[0] = dup(stdin);
	if (fd[0] == -1)
		return (0);
	fd[1] = dup(stdout);
	if (fd[1] == -1)
	{
		ft_close(fd[0]);
		return (0);
	}
	return (1);
}

ft_dup2_fds(int *fd, int *stdfd)
{
	fd[0] = dup2(stdfd[0], 0);
	if (fd[0] == -1)
		return (0);
	fd[1] = dup2(stdfd[1], 1);
	if (fd[1] == -1)
	{
		ft_close(fd[0]);
		return (0);
	}
	return (1);
}
