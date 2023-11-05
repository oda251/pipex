/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:16:12 by yoda              #+#    #+#             */
/*   Updated: 2023/11/06 01:04:51 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *arg, bool former_flag)
{
	char	*msg;

	msg = ft_strdup(strerror(errno));
	if (!msg)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	msg = ft_strtolower(msg);
	ft_puterror("pipex: ");
	if (arg != NULL && former_flag == true)
	{
		ft_puterror(arg);
		ft_puterror(": ");
	}
	ft_puterror(msg);
	free(msg);
	if (arg != NULL && former_flag == false)
	{
		ft_puterror(": ");
		ft_puterror(arg);
	}
	ft_puterror("\n");
}

void	perror_exit(t_pipex *p, char *arg, bool former_flag)
{
	ft_perror(arg, former_flag);
	free_pipex(p);
	exit(EXIT_FAILURE);
}

void	error_invalid_usage(void)
{
	ft_puterror("pipex: too few argument\n");
	exit(EXIT_FAILURE);
}

void	error_cmd_not_found(char *cmd, t_pipex *p)
{
	ft_puterror("pipex: command not found: ");
	ft_puterror(cmd);
	ft_puterror("\n");
	free_pipex(p);
	exit(EXIT_FAILURE);
}
