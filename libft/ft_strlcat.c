/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:11:53 by yoda              #+#    #+#             */
/*   Updated: 2023/09/20 20:11:53 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			d_len;
	const size_t	s_len = ft_strlen(src);
	size_t			i;

	if (dst == NULL && !dstsize)
		return (dstsize + s_len);
	d_len = ft_strlen(dst);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	i = d_len;
	while (i < dstsize - 1 && *src)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (d_len + s_len);
}
