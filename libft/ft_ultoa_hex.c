/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:39:59 by yoda              #+#    #+#             */
/*   Updated: 2023/09/29 19:14:39 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_dest(char **dest, unsigned long n)
{
	int		digit;

	digit = 0;
	while (n)
	{
		n >>= 4;
		digit++;
	}
	*dest = malloc(sizeof(char) * (digit + 1));
	if (!*dest)
		return (0);
	(*dest)[digit] = '\0';
	return (digit);
}

static void	*solve(char **dest, unsigned long n, int up_flag)
{
	int		size;

	size = get_dest(dest, n);
	if (!size)
		return (NULL);
	while (--size >= 0)
	{
		if (up_flag)
			(*dest)[size] = HEX_UP[n & 0b1111];
		else
			(*dest)[size] = HEX_LOW[n & 0b1111];
		n >>= 4;
	}
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

char	*ft_ultoa_hex(unsigned long n, int up_flag)
{
	char	*dest;

	if (n == 0)
	{
		dest = when_zero();
		return (dest);
	}
	solve(&dest, n, up_flag);
	return (dest);
}
