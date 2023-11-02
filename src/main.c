/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:07:19 by yoda              #+#    #+#             */
/*   Updated: 2023/11/02 06:54:03 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_first_input(int *c, char ***v, int *here_doc);

int	main(int c, char **v)
{
	char		***args;
	char		*str;
	int			here_doc;

	if (c < 5)
		arg_error_exit();
	v++;
	c--;
	str = get_first_input(&c, &v, &here_doc);
	args = trans_args(c, v, str);
	pipex_ini(c, args, str, here_doc);
	return (0);
}

char	*get_first_input(int *c, char ***v, int *here_doc)
{
	char	*str;
	int		fd;

	*here_doc = FALSE;
	if (ft_strcmp(*v, "here_doc") == 0)
	{
		*here_doc = TRUE;
		str = read_till_limiter(0, v[1]);
		*v += 2;
		*c -= 2;
	}
	else
	{
		fd = open(**v, O_RDONLY);
		if (fd == -1)
			perror_exit(NULL, **v, 0);
		str = read_till_limiter(fd, "");
	}
	if (!str)
		perror_exit(NULL, NULL, 0);
	return (str);
}
