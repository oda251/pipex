/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:07:19 by yoda              #+#    #+#             */
/*   Updated: 2023/10/31 05:37:02 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int c, char **v)
{
	int			fd;
	int			std_fd[2];
	t_list	*fd_lst;

	if (c != 5)
	{
		ft_puterror("usage: ./pipex file1 cmd1 cmd2 file2\n")
		exit(EXIT_FAILURE);
	}
	fd = ft_open(v[1], O_RDONLY, &fd_lst);
	std_fd[0] = ft_dup(0, &fd_lst);
	std_fd[1] = ft_dup(1, &fd_lst);
	if (pipe(std_fd) == -1)
		error_exit(&fd_lst);
	if (!exec_cmd(v[2], fd, std_fd[1]))
		error_exit(&fd_lst);
	ft_close(fd, &fd_lst);
	ft_close(std_fd[1], &fd_lst);
	fd = ft_open(v[4], O_WRONLY | O_CREAT | O_TRUNC, 0644, &fd_lst);
	if (!exec_cmd(v[3], std_fd[0], fd))
		error_exit(&fd_lst);
	ft_close_all(&fd_lst);
	return (0);
}