/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:23:37 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 05:20:03 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static int	is_path(char *cmd)
{
	if (ft_strchr(cmd, '/') != NULL)
		return (TRUE);
	return (FALSE);
}

static void	check_existance(char **paths, char **cmd, t_pipex *p)
{
	char	*tmp;
	int		i;

	if (is_path(*cmd))
	{
		if (access(*cmd, F_OK) == 0)
			return ;
		ft_free_char_double_p(paths);
		perror_exit(p, *cmd, 0);
	}
	else
	{
		i = 0;
		while (paths[i])
		{
			tmp = ft_strjoin(paths[i], *cmd);
			if (!tmp)
				perror_exit(p, NULL, 0);
			if (access(tmp, F_OK) == 0)
			{
				free(*cmd);
				*cmd = tmp;
				return ;
			}
			free(tmp);
			i++;
		}
	}
	ft_free_char_double_p(paths);
	error_cmd_not_found(*cmd, p);
}

static char	**process_paths(t_pipex *p)
{
	char	**paths;
	char	*tmp;
	int		i;

	paths = ft_split(get_path(p->envp), ":");
	if (!paths)
		perror_exit(p, NULL, 0);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
		{
			ft_free_char_double_p(paths);
			perror_exit(p, NULL, 0);
		}
		free(paths[i]);
		paths[i] = tmp;
		i++;
	}
	return (paths);
}

void	arg_check_cmds(t_pipex *p)
{
	char	**paths;
	int		i;

	paths = process_paths(p);
	i = 0;
	while (p->args[i])
	{
		check_existance(paths, &(p->args[i][0]), p);
		i++;
	}
	i = 0;
	while (p->args[i])
	{
		if (access(p->args[i][0], X_OK) != 0)
			perror_exit(p, p->args[i][0], 0);
		i++;
	}
	p->cmd_size = i;
	ft_free_char_double_p(paths);
}
