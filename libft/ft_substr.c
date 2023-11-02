/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:02:37 by yoda              #+#    #+#             */
/*   Updated: 2023/09/24 04:34:05 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	size;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || !len)
	{
		dest = ft_calloc(1, 1);
		return (dest);
	}
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, size + 1);
	return (dest);
}
