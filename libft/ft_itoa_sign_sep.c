/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_sign_sep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:18:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/01 07:47:02 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_dest(char **dest, long ln)
{
	int		digit;

	digit = 0;
	while (ln)
	{
		ln /= 10;
		digit++;
	}
	*dest = malloc(sizeof(char) * (digit + 1));
	if (!*dest)
		return (0);
	(*dest)[digit] = '\0';
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

static void	*solve(char **dest, long ln)
{
	int		size;

	size = get_dest(dest, ln);
	if (!size)
		return (NULL);
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

char	*ft_itoa_sign_sep(int n, char **sign)
{
	char	*dest;
	long	ln;

	if (n == 0)
	{
		dest = when_zero();
		return (dest);
	}
	ln = n;
	if (n < 0)
	{
		ln *= (-1);
		*sign = "-";
	}
	solve(&dest, ln);
	return (dest);
}
