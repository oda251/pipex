/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:34:58 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 19:57:20 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_pipex p, int infd, int outfd, int count);

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
	{
		if (count < p.cmd_size - 1)
			child(p, fd, pipefd[1], count);
		else
			child(p, fd, p.outfile, count);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
		close(pipefd[1]);
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
	if (tmp < 0)
		perror_exit(&p, NULL, 0);
	tmp = dup2(outfd, STDOUT_FILENO);
	if (tmp < 0)
		perror_exit(&p, NULL, 0);
	if (close(infd) == -1)
		perror_exit(&p, NULL, 0);
	if (close(outfd) == -1)
		perror_exit(&p, NULL, 0);
	if (execve(p.args[count][0], p.args[count], p.envp) == -1)
		perror_exit(&p, p.args[count][0], 0);
}