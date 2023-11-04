/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:34:58 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 19:25:39 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_pipex p, int count);

static void	pipex_init(t_pipex *p)
{
	int	i;

	p->fd = (int *) malloc(sizeof(int) * (p->cmd_size - 1) * 2);
	if (!p->fd)
		perror_exit(p, NULL, 0);
	ft_memset_int(p->fd, -1, (p->cmd_size - 1) * 2);
	p->pid = (pid_t *) malloc(sizeof(pid_t) * p->cmd_size);
	if (!p->pid)
		perror_exit(p, NULL, 0);
	ft_memset_int(p->pid, -1, p->cmd_size);
	i = 0;
	while (i < p->cmd_size - 1)
	{
		if (pipe(p->fd + (i * 2)) == -1)
			return ;
		i++;
	}
}

void	px_dup2(t_pipex *p, int count)
{
	int	tmp;

	if (count == 0)
	{
		tmp = dup2(p->infile, STDIN_FILENO);
		ft_close(&(p->infile));
	}
	else
	{
		tmp = dup2(p->fd[(count - 1) * 2], STDIN_FILENO);
		ft_close(&(p->fd[(count - 1) * 2]));
	}
	if (tmp < 0)
		perror_exit(p, NULL, 0);
	if (count == p->cmd_size - 1)
	{
		tmp = dup2(p->outfile, STDOUT_FILENO);
		ft_close(&(p->outfile));
	}
	else
	{
		tmp = dup2(p->fd[count * 2 + 1], STDOUT_FILENO);
		ft_close(&(p->fd[count * 2 + 1]));
	}
	if (tmp < 0)
		perror_exit(p, NULL, 0);
}

void	pipex(t_pipex p)
{
	int		i;
	pid_t	pid;
	int		status;

	pipex_init(&p);
	i = -1;
	while (++i < p.cmd_size)
	{
		pid = fork();
		if (pid < 0)
			return ;
		if (pid == 0)
			child(p, i);
		else
		{
			// printf("fd: %d\n", p.fd[(i - 1) * 2]);
			// waitpid(pid, &status, WUNTRACED);
			// if (!WIFEXITED(status) && WEXITSTATUS(status) != 0)
			// 	perror_exit(&p, NULL, 0);
			p.pid[i] = pid;
		}
	}
	px_close_all(&p);
	wait(&status);
	free_pipex(&p);
}

void	child(t_pipex p, int count)
{
	px_dup2(&p, count);
	px_close_all(&p);
	if (execve(p.args[count][0], p.args[count], p.envp)
		== -1)
		perror_exit(&p, p.args[count][0], 0);
}
