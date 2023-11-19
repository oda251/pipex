/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:13:13 by yoda              #+#    #+#             */
/*   Updated: 2023/11/19 12:36:18 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	has_here_doc(char *arg);
char	**get_paths(char **envp);

void	init_pipex(t_pipex *p, int argc, char **argv, char **envp)
{
	p->heredoc_flag = has_here_doc(argv[0]);
	if (argc < 4 + p->heredoc_flag || argc > 4 + p->heredoc_flag)
		error_invalid_usage();
	p->cmd_size = argc - p->heredoc_flag - 2;
	p->argv = argv + p->heredoc_flag;
	p->envp = envp;
	p->paths = get_paths(envp);
	p->pid = malloc(sizeof(int) * p->cmd_size);
	if (p->pid == NULL)
	{
		ft_free_char_double_p(p->paths);
		perror_exit(NULL, "malloc", 0);
	}
	ft_memset_int(p->pid, -1, p->cmd_size);
	p->tmp_path = prepare_tmpfile(p);
}

bool	has_here_doc(char *arg)
{
	if (ft_strcmp(arg, "here_doc") == 0)
		return (true);
	else
		return (false);
}

static char	**process_paths(char *env_path)
{
	char	**paths;
	char	*tmp;
	int		i;

	paths = ft_split(env_path, ":");
	if (!paths)
		perror_exit(NULL, "malloc", 0);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
		{
			ft_free_char_double_p(paths);
			perror_exit(NULL, "malloc", 0);
		}
		free(paths[i]);
		paths[i] = tmp;
		i++;
	}
	return (paths);
}

char	**get_paths(char **envp)
{
	int		i;
	char	**empty;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (process_paths(envp[i] + 5));
		i++;
	}
	empty = malloc(sizeof(char *));
	if (!empty)
		perror_exit(NULL, "malloc", 0);
	empty[0] = NULL;
	return (empty);
}
