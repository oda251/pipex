/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:58:54 by yoda              #+#    #+#             */
/*   Updated: 2023/10/28 22:59:27 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int *s, int size)
{
	int	i;
	int	max;

	i = 0;
	max = s[0];
	while (i < size)
	{
		if (s[i] > max)
			max = s[i];
		i++;
	}
	return (max);
}

int	ft_max_index(int *s, int size)
{
	int	i;
	int	max;
	int	max_index;

	i = 0;
	max = s[0];
	max_index = 0;
	while (i < size)
	{
		if (s[i] > max)
		{
			max = s[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}
