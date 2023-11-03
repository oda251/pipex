/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:13:13 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 04:56:32 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ini_pipex(t_pipex *p, char **envp)
{
	p->args = NULL;
	p->cmd_size = 0;
	p->envp = envp;
	p->infile = NONE;
	p->outfile = NONE;
	p->here_doc = FALSE;
	p->fd = NULL;
	p->pid = NULL;
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

char	***trans_args(int c, char **v)
{
	char	***dest;
	int		i;

	dest = (char ***)malloc(sizeof(char **) * (c + 1));
	if (!dest)
		return (NULL);
	ft_bzero(dest, sizeof(char **) * (c + 1));
	i = 0;
	while (i < c)
	{
		dest[i] = ft_split(v[i], " \n\t\v\f\r");
		if (!dest[i])
		{
			ft_free_char_triple_p(dest);
			return (NULL);
		}
		i++;
	}
	return (dest);
}
