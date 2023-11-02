/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:18:51 by yoda              #+#    #+#             */
/*   Updated: 2023/09/29 17:55:29 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_dest(char **dest, long ln, int sign)
{
	int		digit;

	digit = 0;
	if (sign == -1)
		digit++;
	while (ln)
	{
		ln /= 10;
		digit++;
	}
	*dest = malloc(sizeof(char) * (digit + 1));
	if (!*dest)
		return (0);
	(*dest)[digit] = '\0';
	if (sign == -1)
	{
		(*dest)[0] = '-';
		digit--;
	}
	return (digit);
}

static void	put_nums(char *dest, long ln, int size)
{
	while (--size >= 0)
	{
		dest[size] = ln % 10 + '0';
		ln /= 10;
	}
}

static void	*solve(char **dest, long ln, int sign)
{
	int		size;

	size = get_dest(dest, ln, sign);
	if (!size)
		return (NULL);
	if (sign < 0)
		put_nums((*dest) + 1, ln, size);
	else
		put_nums(*dest, ln, size);
	return (dest);
}

static char	*when_zero(void)
{
	char	*dest;

	dest = ft_calloc(1, 2);
	if (!dest)
		return (NULL);
	dest[0] = '0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	ln;
	int		sign;

	if (n == 0)
	{
		dest = when_zero();
		return (dest);
	}
	ln = n;
	sign = 1;
	if (n < 0)
	{
		ln *= (-1);
		sign = -1;
	}
	solve(&dest, ln, sign);
	return (dest);
}
