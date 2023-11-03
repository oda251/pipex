/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:34:58 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 04:47:41 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_pipex p, int count);

static void	pipex_init(t_pipex *p)
{
	int	i;

	p->fd = (int *) malloc(sizeof(int) * (p->cmd_size - 1) * 2);
	if (!p->fd)
		return ;
	p->pid = (int *) malloc(sizeof(int) * p->cmd_size);
	if (!p->pid)
	{
		p->fd = ft_free(p->fd);
		return ;
	}
	ft_memset_int(p->fd, -1, (p->cmd_size - 1) * 2);
	ft_memset_int(p->pid, -1, p->cmd_size);
	i = 0;
	while (i < p->cmd_size - 1)
	{
		if (pipe(p->fd + (i * 2)) == -1)
			return ;
		i++;
	}
}

void	pipex(t_pipex *p)
{
	int		i;
	pid_t	pid;

	pipex_init(p);
	i = -1;
	while (++i < p->cmd_size)
	{
		pid = fork();
		if (pid < 0)
			return ;
		if (pid == 0)
			child(*p, i);
		else
		{
			p->pid[i] = pid;
			if (i != 0)
				ft_close(&(p->fd[(i - 1) * 2]));
			if (i != p->cmd_size - 1)
				ft_close(&(p->fd[i * 2 + 1]));
		}
	}
	wait(NULL);
}

void	child(t_pipex p, int count)
{
	int	tmp;

	if (count == 0)
		tmp = dup2(p.infile, STDIN_FILENO);
	else
		tmp = dup2(p.fd[(count - 1) * 2], STDIN_FILENO);
	if (tmp < 0)
		perror_exit(&p, NULL, 0);
	if (count == p.cmd_size - 1)
		tmp = dup2(p.outfile, STDOUT_FILENO);
	else
		tmp = dup2(p.fd[count * 2 + 1], STDOUT_FILENO);
	if (tmp < 0)
	{
		ft_close(STDIN_FILENO);
		perror_exit(&p, NULL, 0);
	}
	px_close_all(&p);
	if (execve(p.args[count][0], p.args[count], p.envp)
		== -1)
		perror_exit(&p, p.args[count][0], 0);
}
