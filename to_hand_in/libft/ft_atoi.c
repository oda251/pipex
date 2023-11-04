/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:28:13 by yoda              #+#    #+#             */
/*   Updated: 2023/09/29 17:55:51 by yoda             ###   ########.fr       */
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

static int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;

	while (ft_isspace(*str))
		str++;
	if (!*str || !(*str == '-' || *str == '+' || ft_isdigit(*str)))
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
