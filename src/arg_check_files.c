/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:22:05 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 13:17:29 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	file_if_readable(char *file)
{
	if (access(file, F_OK) == 0)
		return (TRUE);
	if (access(file, R_OK) == 0)
		return (TRUE);
	return (FALSE);
}

static int	file_if_writable(char *file)
{
	if (access(file, F_OK) == -1 
		|| access(file, W_OK) == 0)
		return (TRUE);
	return (FALSE);
}

int	arg_check_files(int c, char **v, int here_doc)
{
	if (!here_doc && !file_if_readable(v[0]))
		perror_exit(NULL, v[0], 0);
	if (!file_if_writable(v[c - 1]))
		perror_exit(NULL, v[c - 1], 0);
	return (TRUE);
}
