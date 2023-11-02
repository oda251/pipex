/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:36:02 by yoda              #+#    #+#             */
/*   Updated: 2023/09/24 05:42:50 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_chr;
	unsigned char	*src_chr;
	size_t			i;

	i = -1;
	dst_chr = dst;
	src_chr = (void *) src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (++i < len)
			dst_chr[i] = src_chr[i];
	}
	else
	{
		while (len--)
			dst_chr[len] = src_chr[len];
	}
	return (dst);
}
