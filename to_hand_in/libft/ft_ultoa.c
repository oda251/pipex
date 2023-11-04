/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:58:36 by yoda              #+#    #+#             */
/*   Updated: 2023/09/29 19:14:18 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_dest(char **dest, unsigned long n)
{
	int		digit;

	digit = 0;
	while (n)
	{
		n /= 10;
		digit++;
	}
	*dest = malloc(sizeof(char) * (digit + 1));
	if (!*dest)
		return (0);
	(*dest)[digit] = '\0';
	return (digit);
}

static void	*solve(char **dest, unsigned long n)
{
	int		size;

	size = get_dest(dest, n);
	if (!size)
		return (NULL);
	while (--size >= 0)
	{
		(*dest)[size] = n % 10 + '0';
		n /= 10;
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

char	*ft_ultoa(unsigned long n)
{
	char	*dest;

	if (n == 0)
	{
		dest = when_zero();
		return (dest);
	}
	solve(&dest, n);
	return (dest);
}
