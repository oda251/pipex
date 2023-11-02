/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_only_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 04:55:26 by yoda              #+#    #+#             */
/*   Updated: 2023/10/01 05:11:15 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	solve(const char *str, const int sign)
{
	unsigned long	num;
	unsigned long	tmp;

	num = 0;
	while (ft_isdigit(*str))
	{
		tmp = num;
		num = num * 10 + (*str - '0');
		if (sign > 0)
		{
			if (num >= (unsigned long) LONG_MAX || tmp > num)
				return ((int) LONG_MAX);
		}
		else if (num >= (unsigned long) LONG_MAX + 1 || tmp > num)
			return ((int) LONG_MIN);
		str++;
	}
	return (sign * num);
}

int	ft_atoi_only_num(const char *str)
{
	int	sign;

	if (!ft_isdigit(*str))
		return (0);
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (solve(str, sign));
}
