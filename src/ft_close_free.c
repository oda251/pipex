/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:24:33 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 21:23:55 by yoda             ###   ########.fr       */
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

static void	*px_close_all(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < (p->cmd_size - 1) * 2)
		ft_close(&(p->fd[i]));
	p->fd = ft_free(p->fd);
	return (NULL);
}

void	free_pipex(t_pipex *p)
{
	if (!p)
		return ;
	if (p->args)
		ft_free_char_triple_p(p->args);
	ft_close(&(p->infile));
	ft_close(&(p->outfile));
	if (p->here_doc)
	{
		if (access("./tmp", F_OK) == 0)
			unlink("./tmp");
	}
	px_close_all(p);
	ft_free(p->pid);
	return ;
}
