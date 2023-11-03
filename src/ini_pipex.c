/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:13:13 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 20:13:24 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ini_pipex(t_pipex *p, char **envp)
{
	p->args = NULL;
	p->arg_size = 0;
	p->cmd_size = 0;
	p->envp = envp;
	p->infile = NONE;
	p->outfile = NONE;
	p->here_doc = FALSE;
}

void	has_here_doc(int *c, char ***v, t_pipex *p)
{
	if (ft_strcmp((*v)[0], "here_doc") == 0)
	{
		p->here_doc = TRUE;
		(*c)--;
		(*v)++;
	}
	else
		p->here_doc = FALSE;
}
