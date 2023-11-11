/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:36:15 by yoda              #+#    #+#             */
/*   Updated: 2023/11/11 20:00:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(int *pipefd, int *fd);
void	child(t_pipex p, int fd, int *pipefd, int count);
void	prepare_infd(t_pipex p, int *fd, int count);
void	prepare_outfd(t_pipex p, int *fd, int count);

void	execute_cmds(t_pipex p)
{
	int	i;
	int	pipefd[2];
	int	fd;

	i = -1;
	fd = -1;
	while (++i < p.cmd_size)
	{
		if (i != p.cmd_size - 1 && pipe(pipefd) == -1)
			perror_exit(&p, pipe, 0);
		else if (i == p.cmd_size - 1)
			ft_memset_int(pipefd, -1, 2);
		p.pid[i] = fork();
		if (p.pid[i] < 0)
			perror_exit(&p, "fork", 0);
		else if (p.pid[i] == 0)
			child(p, fd, pipefd, i);
		else
			parent(pipefd, &fd);
	}
	i = -1;
	while (++i < p.cmd_size)
		waitpid(p.pid[i], NULL, 0);
	free_pipex(&p);
}

void	parent(int *pipefd, int *fd)
{
	ft_close(&(pipefd[1]));
	if (*fd != -1)
		ft_close(fd);
	*fd = pipefd[0];
}

void	child(t_pipex p, int fd, int *pipefd, int count)
{
	t_cmd	cmd;

	ft_close(&(pipefd[0]));
	prepare_infd(p, &fd, count);
	prepare_outfd(p, &(pipefd[1]), count);
	cmd = parse_cmd(&p, count + 1);
	execve(cmd.argv[0], cmd.argv, p.envp);
	perror_exit(&p, cmd.row_cmd, 0);
}

void	prepare_infd(t_pipex p, int *fd, int count)
{
	char	*path;

	if (p.heredoc_flag == true)
		path = p.tmp_path;
	else
		path = p.argv[0];
	if (count == 0)
		*fd = open(path, O_RDONLY);
	else if (count == 0 && p.heredoc_flag)
		*fd = open(path, O_RDONLY);
	if (*fd < 0)
	{
		if (count == 0)
			perror_exit(&p, path, 1);
		else
			perror_exit(&p, NULL, 1);
	}
	if (dup2(*fd, STDIN_FILENO) < 0 || close(*fd) < 0)
		perror_exit(&p, NULL, 0);
}

void	prepare_outfd(t_pipex p, int *fd, int count)
{
	int	open_opt;

	if (p.heredoc_flag == true)
		open_opt = O_WRONLY | O_CREAT | O_APPEND;
	else
		open_opt = O_WRONLY | O_CREAT | O_TRUNC;
	if (count == p.cmd_size - 1)
		*fd = open(p.argv[p.cmd_size + 1], open_opt, 0644);
	if (*fd < 0)
	{
		if (count == p.cmd_size - 1)
			perror_exit(&p, p.argv[p.cmd_size + 1], 1);
		else
			perror_exit(&p, NULL, 1);
	}
	if (dup2(*fd, STDOUT_FILENO) < 0 || close(*fd) < 0)
		perror_exit(&p, NULL, 0);
}
