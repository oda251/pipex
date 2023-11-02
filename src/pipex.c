/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:34:58 by yoda              #+#    #+#             */
/*   Updated: 2023/11/02 08:16:07 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *fd, int c, char ***args, int here_doc);

void	pipex_ini(int c, char ***args, char *str, int here_doc)
{
	int		fd[4];;
	int		pid;
	int		status;

	if (pipe(fd) == -1 || !ft_dup_fds(fd + 2, 0, 1))
		perror_free_args_exit(NULL, args);
	pid = fork();
	if (pid < 0)
		perror_free_args_exit(fd, args);
	else if (pid == 0)
		child(fd, c, args, here_doc);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			write(fd[1], str, ft_strlen(str));
		free(str);
	}
	ft_close_all(fd);
	ft_close_all(fd + 2);
	free_args(args);
}

void	pipex_rec(int c, char ***args, int *stdfd, int here_doc)
{
	int		fd[2];
	int		pid;
	int		status;

	if (c == 2)
		return (pipex_fin(args, stdfd, here_doc));
	if (pipe(fd) == -1)
		perror_free_args_exit(fd, args);
	pid = fork();
	if (pid < 0)
		perror_free_args_exit(fd, args);
	else if (pid == 0)
		child(fd, c, args, here_doc);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			pipex_rec(c - 1, args + 1, fd, stdfd);
	}
	ft_close_all(fd);
	return ;
}

void	pipex_fin(char ***args, int *stdfd, int here_doc)
{
	int		fd;
	int		fd2;

	if (!pipe(fd))
		perror_exit(NULL, NULL, 0);
	if (here_doc)
		fd = open(args[1][0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(args[1][0], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		perror_exit(NULL, args[1][0], 0);
	dup2(fd, 1);
	execve(args[0][0], args[0], NULL);
	close(fd);
}

void	child(int *fd, int c, char ***args, int here_doc)
{
	ft_close_all(fd);
	if (!ft_dup2_fds(fd, fd + 2))
		perror_free_args_exit(fd, args);
	pipex_rec(c - 1, args + 1, fd + 2, here_doc);
}
