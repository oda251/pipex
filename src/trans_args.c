/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:20:05 by yoda              #+#    #+#             */
/*   Updated: 2023/11/02 06:54:11 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***trans_args(int c, char **v, char *str)
{
	char	***dest;
	int		i;

	dest = (char ***)malloc(sizeof(char **) * (c + 1));
	if (!dest)
	{
		free(str);
		perror_exit(NULL, NULL, 0);
	}
	ft_bzero(dest, sizeof(char **) * (c + 1));
	i = 0;
	while (i < c)
	{
		dest[i] = ft_split(v[i], " \n\t\v\f\r");
		if (!dest[i])
		{
			free(str);
			perror_free_args_exit(NULL, dest);
		}
		i++;
	}
	return (dest);
}