/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:34:58 by yoda              #+#    #+#             */
/*   Updated: 2023/11/05 19:38:30 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_pipex p, int infd, int outfd, int count);

void	pipex_sub(t_pipex p, int fd, int *pipefd, int count)
{
	if (count < p.cmd_size - 1)
		child(p, fd, pipefd[1], count);
	else
		child(p, fd, p.outfile, count);
}

void	pipex(t_pipex p, int fd, int count)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	if (pipe(pipefd) == -1)
		perror_exit(&p, NULL, 0);
	pid = fork();
	if (pid < 0)
		perror_exit(&p, NULL, 0);
	else if (pid == 0)
		pipex_sub(p, fd, pipefd, count);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		if (close(pipefd[1]) == -1 || close(fd) == -1)
			perror_exit(&p, NULL, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0
			&& count < p.cmd_size - 1)
			pipex(p, pipefd[0], count + 1);
	}
	free_pipex(&p);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		exit(0);
	else
		exit(1);
}

void	child(t_pipex p, int infd, int outfd, int count)
{
	int	tmp;

	tmp = dup2(infd, STDIN_FILENO);
	if (tmp < 0 || close(infd) == -1)
		perror_exit(&p, NULL, 0);
	tmp = dup2(outfd, STDOUT_FILENO);
	if (tmp < 0 || close(outfd) == -1)
	{
		close(STDIN_FILENO);
		perror_exit(&p, NULL, 0);
	}
	if (execve(p.args[count][0], p.args[count], p.envp) == -1)
		perror_exit(&p, p.args[count][0], 0);
}
