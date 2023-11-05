/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:07:19 by yoda              #+#    #+#             */
/*   Updated: 2023/11/06 03:50:20 by yoda             ###   ########.fr       */
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
//     int     status;
//     char    buf[50];

//     snprintf(buf, 50, "leaks %d &> leaksout", getpid());
//     status = system(buf);
//     if (status)
//     {
//         write(2, "leak!!!\n", 8);
//         system("cat leaksout >/dev/stderr");
//         exit(1);
//     }
// }