/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:07:19 by yoda              #+#    #+#             */
/*   Updated: 2023/11/11 22:21:07 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc < 5)
		error_invalid_usage();
	init_pipex(&p, argc - 1, argv + 1, envp);
	execute_cmds(p);
	return (0);
}

// __attribute__((destructor))
// void    destructor(void)
// {
//     system("leaks pipex");
// }