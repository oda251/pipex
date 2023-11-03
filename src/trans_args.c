/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:20:05 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 20:49:18 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***trans_args(int c, char **v)
{
	char	***dest;
	int		i;

	dest = (char ***)malloc(sizeof(char **) * (c + 1));
	if (!dest)
		return (NULL);
	ft_bzero(dest, sizeof(char **) * (c + 1));
	i = 0;
	while (i < c)
	{
		dest[i] = ft_split(v[i], " \n\t\v\f\r");
		if (!dest[i])
		{
			ft_free_char_triple_p(dest);
			return (NULL);
		}
		i++;
	}
	return (dest);
}