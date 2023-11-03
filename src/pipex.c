/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:34:58 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 16:55:17 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int fd, int *pipefd, t_pipex p, int count);

void	pipex(t_pipex p, int fd, int count)
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		perror_exit(&p, NULL, 0);
	if (count < p.arg_count - 3)
		pipex(p, pipefd[1], count + 1);
	pid = fork();
	if (pid == -1)
		perror_exit(&p, NULL, 0);
	if (pid == 0)
		child(fd, pipefd, p, count);
	else
	{
		waitpid(pid, NULL, 0);
		ft_close(&(pipefd[0]));
		ft_close(&(pipefd[1]));
	}
}

void	child(int fd, int *pipefd, t_pipex p, int count)
{
	int	tmp;

	if (count == p.arg_count - 3)
		tmp = dup2(p.infile, STDIN_FILENO);
	else
		tmp = dup2(pipefd[0], STDIN_FILENO);
	if (tmp == -1)
		perror_exit(&p, NULL, 0);
	tmp = dup2(fd, STDOUT_FILENO);
	if (tmp == -1)
		perror_exit(&p, NULL, 0);
	ft_close(&(pipefd[0]));
	ft_close(&(pipefd[1]));
	// execve(p.args[p.arg_count - count - 2][0],
	// 	p.args[p.arg_count - count - 2], p.envp);
	char buf[100];
	int r = read(STDIN_FILENO, buf, 100);
	buf[r] = '\0';
	printf("%d: %s\n", count, buf);
}