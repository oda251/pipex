/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:13:13 by yoda              #+#    #+#             */
/*   Updated: 2023/11/05 22:47:50 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	has_here_doc(char *arg);
void	create_pipes(t_pipex *p);

void	init_pipex(t_pipex *p, int argc, char **argv, char **envp)
{
	if (argc <= 5)
		error_invalid_usage();
	p->heredoc_flag = has_here_doc(argv[0]);
	p->cmd_size = argc - p->heredoc_flag - 2;
	p->argv = argv + p->heredoc_flag;
	p->argv = envp;
	p->pid = malloc(sizeof(int) * p->cmd_size);
	if (p->pid == NULL)
		/* error */;
	ft_memset_int(p->pid, -1, p->cmd_size);
	create_pipes(p);
}

bool	has_here_doc(char *arg)
{
	if (ft_strcmp(arg, "here_doc") == 0)
		return (true);
	else
		return (false);
}

void	create_pipes(t_pipex *p)
{
	int	i;

	p->pipe = malloc(sizeof(int) * (p->cmd_size - 1) * 2);
	if (p->pipe == NULL)
	{
		free(p->pid);
		/* error */;
	}
	i = 0;
	while (i < p->cmd_size - 1)
	{
		if (pipe(p->pipe + i) == -1)
		{
			while (--i >= 0)
				ft_close(&(p->pipe[i]));
		}
		i += 2;
	}
	ft_memset_int(p->pipe, -1, (p->cmd_size - 1) * 2);
}

char	***trans_args(int c, char **v)
{
	char	***dest;
	int		i;

	dest = (char ***)malloc(sizeof(char **) * (c + 1));
	if (!dest)
		perror_exit(NULL, NULL, 0);
	ft_bzero(dest, sizeof(char **) * (c + 1));
	i = 0;
	while (i < c)
	{
		dest[i] = ft_split(v[i], " \n\t\v\f\r");
		if (!dest[i])
		{
			ft_free_char_triple_p(dest);
			perror_exit(NULL, NULL, 0);
		}
		i++;
	}
	return (dest);
}
