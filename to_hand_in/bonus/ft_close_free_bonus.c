/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:24:33 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 19:49:03 by yoda             ###   ########.fr       */
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

void	free_pipex(t_pipex *p)
{
	if (!p)
		return ;
	if (p->args)
		ft_free_char_triple_p(p->args);
	if (p->here_doc)
	{
		if (access("./tmp", F_OK) == 0)
			unlink("./tmp");
	}
	ft_close(&(p->infile));
	ft_close(&(p->outfile));
	return ;
}
