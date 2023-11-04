/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:36:02 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 20:25:15 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *) b;
	i = -1;
	while (++i < len)
		*(dest + i) = (unsigned char) c;
	return (dest);
}

void	*ft_memset_int(int *b, int n, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		*(b + i) = n;
	return (b);
}
