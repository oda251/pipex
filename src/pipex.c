/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:34:58 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 22:04:04 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	child(t_pipex p, int count);

// static void	pipex_init(t_pipex *p)
// {
// 	int	i;

// 	p->fd = (int *) malloc(sizeof(int) * (p->cmd_size - 1) * 2);
// 	if (!p->fd)
// 		return ;
// 	p->pid = (int *) malloc(sizeof(int) * p->cmd_size);
// 	if (!p->pid)
// 	{
// 		p->fd = ft_free(p->fd);
// 		return ;
// 	}
// 	ft_memset_int(p->fd, -1, (p->cmd_size - 1) * 2);
// 	ft_memset_int(p->fd, -1, p->cmd_size);
// 	i = 0;
// 	while (i < p->cmd_size - 1)
// 	{
// 		if (pipe(p->fd + (i * 2)) == -1)
// 			return ;
// 	}
// }

// void	pipex(t_pipex *p)
// {
// 	int		i;
// 	pid_t	pid;

// 	pipex_init(p);
// 	i = 0;
// 	while (i < p->cmd_size)
// 	{
// 		pid = fork();
// 		if (pid < 0)
// 			return ;
// 		if (pid == 0)
// 			child(*p, i);
// 		else
// 		{
// 			p->pid[i] = pid;
// 			ft_close(&(p->fd[2 * (p->cmd_size - i) - 1]));
// 			ft_close(&(p->fd[2 * (p->cmd_size - i - 1)]));
// 		}
// 	}
// }

// void	child(t_pipex p, int count)
// {
// 	int	tmp;
// 	int	status;

// 	if (count != p.cmd_size - 1)
// 		waitpid(p.pid[count + 1], &status, 0);
// 	if (count == 0)
// 		tmp = dup2(p.infile, STDIN_FILENO);
// 	else
// 		tmp = dup2(p.fd[2 * (p.cmd_size - count) - 1], STDIN_FILENO);
// 	ft_close(&(p.fd[2 * (p.cmd_size - count) - 1]));
// 	if (tmp < 0)
// 		perror_exit(&p, NULL, 0);
// 	if (count == p.cmd_size - 1)
// 		tmp = dup2(p.outfile, STDOUT_FILENO);
// 	else
// 		tmp = dup2(p.fd[2 * (p.cmd_size - count - 1)], STDOUT_FILENO);
// 	ft_close(&(p.fd[2 * (p.cmd_size - count - 1)]));
// 	if (tmp < 0)
// 	{
// 		ft_close(STDIN_FILENO);
// 		perror_exit(&p, NULL, 0);
// 	}
// 	execve(p.args[count][0], p.args[count], p.envp);
// }
