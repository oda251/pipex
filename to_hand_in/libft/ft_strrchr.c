/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_strchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@studen.42tokyo.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 02:54:18 by yoda              #+#    #+#             */
/*   Updated: 2023/09/20 02:54:18 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((unsigned char) c == '\0')
		return ((char *) s + i);
	while (i != 0)
	{
		--i;
		if (s[i] == (unsigned char) c)
			return ((char *) s + i);
		if (i == 0)
			break ;
	}
	return (NULL);
}
