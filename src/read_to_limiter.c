/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_limiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:50:30 by yoda              #+#    #+#             */
/*   Updated: 2023/11/02 05:44:26 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	detect_limiter(char *str, char *limiter, size_t len_str, size_t len_limiter)
{
	size_t	i;

	if (len_str < len_limiter)
		return (FALSE);
	i = len_str - len_limiter;
	while (i < len_str)
	{
		if (str[i] != limiter[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static char	*get_str_px(int fd, char *limiter)
{
	char					*str;
	char					*new;
	char					buf[1];
	size_t				len_str;
	const size_t	len_limiter = ft_strlen(limiter);
	size_t				i;

	str = NULL;
	len_str = 0;
	while (read(fd, buf, 1) > 0)
	{
		new = ft_strjoin(str, buf);
		if (str)
			free(str);
		if (!new)
			return (NULL);
		str = new;
		len_str++;
		if (len_limiter
			&& detect_limiter(new, limiter, len_str, len_limiter))
			return (new);
	}
	return (str);
}

char	*read_till_limiter(int fd, char *limiter)
{
	char	*str;

	if (fd < 0)
		return (NULL);
	str = get_str_px(fd, limiter);
	return (str);
}
