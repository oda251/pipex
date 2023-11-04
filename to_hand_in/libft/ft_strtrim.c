/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:24:41 by yoda              #+#    #+#             */
/*   Updated: 2023/09/26 18:05:13 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && in_set(s1[i], set))
		i++;
	return (i);
}

static size_t	get_len(char const *s1, char const *set, const size_t start)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0 && in_set(s1[i - 1], set))
	{
		i--;
		if (i < start)
			return (0);
	}
	return (i - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	len = get_len(s1, set, start);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + start, len + 1);
	return (dest);
}
