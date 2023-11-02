/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:24:33 by yoda              #+#    #+#             */
/*   Updated: 2023/11/02 03:17:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int *fd)
{
	if (*fd == -1)
		return ;
	close(*fd);
	*fd = -1;
}

void	ft_close_all(int *fd_lst)
{
	int	i;

	if (!fd_lst)
		return ;
	i = 0;
	while (i < 2)
	{
		ft_close(fd_lst[i]);
		i++;
	}
}

static void	free_args_sub(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
	return ;
}

void	free_args(char ***args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free_args_sub(args[i]);
		i++;
	}
	free(args);
	return ;
}