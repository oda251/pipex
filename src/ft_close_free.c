/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:24:33 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 14:46:07 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int *fd)
{
	if (*fd > 2)
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
		ft_close(&(fd_lst[i]));
		i++;
	}
}

void	free_char_double_p(char **arg)
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
		free_char_double_p(args[i]);
		i++;
	}
	free(args);
	return ;
}

void	free_pipex(t_pipex *p)
{
	if (!p)
		return ;
	if (p->args)
		free_args(p->args);
	ft_close(&(p->infile));
	ft_close(&(p->outfile));
	if (p->here_doc)
	{
		if (access("./tmp", F_OK) == 0)
			unlink("./tmp");
	}
	return ;
}