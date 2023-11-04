/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:16:12 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 04:52:21 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *arg)
{
	char	*msg;

	ft_puterror("pipex: ");
	msg = ft_strdup(strerror(errno));
	if (!msg)
		ft_puterror("failed to allocate memory");
	else
	{
		msg = ft_strtolower(msg);
		ft_puterror(msg);
		free(msg);
		if (arg)
		{
			ft_puterror(": ");
			ft_puterror(arg);
		}
	}
	ft_puterror("\n");
}

void	perror_exit(t_pipex *p, char *arg, int free_flag)
{
	ft_perror(arg);
	if (free_flag)
		free(arg);
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
