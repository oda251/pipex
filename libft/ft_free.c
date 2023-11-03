/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:00:39 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 20:17:42 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

void	*ft_free_char_double_p(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
	return (NULL);
}

void	*ft_free_char_triple_p(char ***args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		ft_free_char_double_p(args[i]);
		i++;
	}
	free(args);
	return (NULL);
}
