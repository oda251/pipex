/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:54:38 by yoda              #+#    #+#             */
/*   Updated: 2023/10/28 22:01:47 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int *s, int size)
{
	int	i;
	int	min;

	i = 0;
	min = s[0];
	while (i < size)
	{
		if (s[i] < min)
			min = s[i];
		i++;
	}
	return (min);
}

int	ft_min_index(int *s, int size)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min = s[0];
	min_index = 0;
	while (i < size)
	{
		if (s[i] < min)
		{
			min = s[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
