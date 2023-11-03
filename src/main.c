/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:07:19 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 04:46:31 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int c, char **v, char **envp)
{
	t_pipex	p;

	if (c < 5)
		error_invalid_usage();
	v++;
	c--;
	ini_pipex(&p, envp);
	has_here_doc(&c, &v, &p);
	if (c < 4)
		error_invalid_usage();
	arg_check_files(c, v, &p);
	p.args = trans_args(c - 2, v + 1);
	if (!p.args)
		perror_exit(&p, NULL, 0);
	arg_check_cmds(&p);
	pipex(&p);
	free_pipex(&p);
	return (0);
}
