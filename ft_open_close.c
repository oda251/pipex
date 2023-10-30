/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:24:33 by yoda              #+#    #+#             */
/*   Updated: 2023/10/31 05:35:15 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(char *file, int flag, t_list **fd_lst)
{
	int	fd;

	fd = open(file, flag);
	if (fd == -1)
		error_exit(fd_lst);
	ft_lstadd_back(fd_lst, ft_lstnew(fd));
	if (!fd_lst)
		error_exit(fd_lst);
	return (fd);
}

void	ft_close(int fd, t_list **fd_lst)
{
	if (close(fd) == -1)
		error_exit(fd_lst);
	ft_lstdelone(fd_lst, fd);
}

int	ft_dup(char *file, t_list **fd_lst)
{
	int	fd;

	fd = dup(file);
	if (fd == -1)
		error_exit(fd_lst);
	ft_lstadd_back(fd_lst, ft_lstnew(fd));
	if (!fd_lst)
		error_exit(fd_lst);
	return (fd);
}

void	ft_close_all(t_list **fd_lst)
{
	ft_lstclear(fd_lst, close);
}