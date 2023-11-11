/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:16:12 by yoda              #+#    #+#             */
/*   Updated: 2023/11/11 22:43:09 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *arg, bool former_flag)
{
	ft_puterror(ERROR_HEADER);
	if (arg != NULL && former_flag == true)
	{
		ft_puterror(arg);
		ft_puterror(": ");
	}
	ft_puterror(strerror(errno));
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
	ft_puterror(ERROR_HEADER);
	ft_puterror("invalid arguments size\n");
	exit(EXIT_FAILURE);
}

void	error_cmd_not_found(char *cmd)
{
	ft_puterror(ERROR_HEADER);
	ft_puterror(cmd);
	ft_puterror(": command not found");
	ft_puterror("\n");
	ft_free(cmd);
	exit(EXIT_FAILURE);
}
