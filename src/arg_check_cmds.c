/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:23:37 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 16:12:25 by yoda             ###   ########.fr       */
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

static int	check_existance(char **paths, char **cmd)
{
	char	*tmp;
	char	*full_path;
	int		i;

	if (access(*cmd, F_OK) == 0)
		return (TRUE);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, *cmd);
		free(tmp);
		if (access(full_path, F_OK) == 0)
		{
			free(*cmd);
			*cmd = full_path;
			return (TRUE);
		}
		free(full_path);
		i++;
	}
	return (FALSE);
}

void	arg_check_cmds(char **envp, t_pipex p)
{
	char	**paths;
	int		i;

	paths = ft_split(get_path(envp), ":");
	if (!paths)
		perror_exit(NULL, NULL, 0);
	i = 1;
	while (p.args[i + 1])
	{
		if (!check_existance(paths, &(p.args[i][0])))
		{
			error_cmd_not_found(p.args[i][0]);
			free_args(p.args);
			free_char_double_p(paths);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	p.arg_count = i + 1;
	free_char_double_p(paths);
}