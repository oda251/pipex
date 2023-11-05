/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:24:33 by yoda              #+#    #+#             */
/*   Updated: 2023/11/06 04:00:14 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int *fd)
{
	if (*fd < 0)
		return ;
	if (close(*fd) < 0)
		perror_exit(NULL, "close", 0);
	*fd = -1;
}

void	free_pipex(t_pipex *p)
{
	if (!p)
		return ;
	ft_free(p->pid);
	ft_free_char_double_p(p->paths);
	if (p->tmp_path && p->heredoc_flag
		&& access(p->tmp_path, F_OK) == 0)
		unlink(p->tmp_path);
	ft_free(p->tmp_path);
	return ;
}
