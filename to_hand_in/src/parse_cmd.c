/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 03:02:41 by yoda              #+#    #+#             */
/*   Updated: 2023/11/06 04:12:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(t_pipex *p, char *row_cmd);
int		is_path(char *row_cmd, t_pipex *p);
char	*merge_if_accessable(t_pipex *p, char *row_cmd);

t_cmd	parse_cmd(t_pipex *p, int index)
{
	t_cmd	cmd;

	cmd.argv = ft_split(p->argv[index], SPACE);
	if (cmd.argv == NULL)
		perror_exit(p, NULL, 0);
	cmd.row_cmd = cmd.argv[0];
	cmd.argv[0] = get_cmd_path(p, cmd.row_cmd);
	if (cmd.argv[0] == NULL)
		perror_exit(p, NULL, 0);
	return (cmd);
}

char	*get_cmd_path(t_pipex *p, char *row_cmd)
{
	if (is_path(row_cmd, p))
		return (ft_strdup(row_cmd));
	else
		return (merge_if_accessable(p, row_cmd));
}

int	is_path(char *row_cmd, t_pipex *p)
{
	if (ft_strchr(row_cmd, '/') != NULL)
	{
		if (access(row_cmd, F_OK) != 0)
			error_cmd_not_found(row_cmd, p);
		if (access(row_cmd, X_OK) != 0)
			perror_exit(p, row_cmd, 0);
		return (true);
	}
	else
		return (false);
}

static void	*m_i_a_sub(
	t_pipex *p, char *row_cmd, bool is_exist, int error_num)
{
	if (is_exist == false)
		error_cmd_not_found(row_cmd, p);
	errno = error_num;
	perror_exit(p, row_cmd, 0);
	return (NULL);
}

char	*merge_if_accessable(t_pipex *p, char *row_cmd)
{
	char	*cmd;
	int		i;
	bool	is_exist;
	int		error_num;

	is_exist = false;
	i = 0;
	while (p->paths[i])
	{
		cmd = ft_strjoin(p->paths[i], row_cmd);
		if (cmd == NULL)
			perror_exit(p, NULL, 0);
		if (access(cmd, F_OK) == 0)
		{
			is_exist = true;
			if (access(cmd, X_OK) == 0)
				return (cmd);
			error_num = errno;
		}
		free(cmd);
		i++;
	}
	return (m_i_a_sub(p, row_cmd, is_exist, error_num));
}
