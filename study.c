/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:39:20 by yoda              #+#    #+#             */
/*   Updated: 2023/10/31 05:00:12 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int c, char **v)
{
	char *path = "./pipex.h";
	/*
	F_OK: existence
	R_OK: read permission
	W_OK: write permission
	X_OK: execute permission
	*/
	printf("%d\n", access(path, F_OK));
	/*
	perror: print error message
	strerror: return error message
	errno: error number (global variable that is set when error occurs by system call)
	*/
	perror("access: ");
	printf("access: %s\n", strerror(errno));
	/*
	open: open file
	O_RDONLY: read only
	O_WRONLY: write only
	O_RDWR: read and write
	O_CREAT: create file if not exist
	O_EXCL: error if file exist
	O_TRUNC: truncate file
	O_APPEND: append to file
	dup: duplicate file descriptor
	dup2: duplicate file descriptor and set to specified file descriptor
	*/
	int fd = open(path, O_RDONLY);
	int fd_c = dup(fd);
	int fd_cc = dup2(fd, 42);
	close(fd);
	close(fd_c);
	close(fd_cc);
	/*
	execve: execute program
		first argument: path to program
		second argument: array of arguments
		third argument: array of environment variables
	fork: create child process;
		return 0 to child process, return child process id to parent process
	pipe: create pipe;
		connect file descriptor of two processes
			first argument: array of file descriptor
				pipefd[0]: read end
				pipefd[1]: write end
		return 0 if success, return -1 if error
	unlink: delete file
		first argument: path to file
	wait: wait for child process to finish
		first argument: pointer to status
		return child process id if success, return -1 if error
	waidpid: wait for child process to finish
		first argument: child process id
		second argument: pointer to status
		third argument: option
			WNOHANG: return immediately if no child process has finished
		return child process id if success, return -1 if error
	*/
}