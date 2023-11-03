/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:04:33 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 22:24:33 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void	child(int fd[2])
{
	int		infile_fd;
	char	*argv[3];

	infile_fd = open("infile", O_RDONLY);
	if (infile_fd == -1)
		exit(1);
	if (close(fd[0]))
		exit(1);
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		exit(1);
	if (close(infile_fd))
		exit(1);
	close(infile_fd);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit(1);
	if (close(fd[1]))
		exit(1);
	argv[0] = "cat";
	argv[1] = NULL;
	if (execve("/bin/cat", argv, NULL) == -1)
		exit(1);
}

void	parent(int fd[2])
{
	int		outfile_fd;
	char	*argv[3];

	outfile_fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile_fd == -1)
		exit(1);
	if (close(fd[1]))
		exit(1);
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		exit(1);
	if (close(outfile_fd))
		exit(1);
	close(outfile_fd);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit(1);
	if (close(fd[0]))
		exit(1);
	argv[0] = "cat";
	argv[1] = "-e";
	argv[2] = NULL;
	if (execve("/bin/cat", argv, NULL) == -1)
		exit(1);
}

int	main(void)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		child(fd);
	else
		parent(fd);
}