/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 02:46:29 by yoda              #+#    #+#             */
/*   Updated: 2023/11/11 20:05:20 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_heredoc(t_pipex *p, char *path);

char	*prepare_tmpfile(t_pipex *p)
{
	int		i;
	char	*path;
	char	*tmp;

	if (p->heredoc_flag == false)
		return (NULL);
	i = 0;
	while (true)
	{
		tmp = ft_itoa(i++);
		if (!tmp)
			perror_exit(p, "malloc", 0);
		path = ft_strjoin(TMP_PATH, tmp);
		free(tmp);
		if (!path)
			perror_exit(p, "malloc", 0);
		if (access(path, F_OK) != 0)
			break ;
	}
	write_heredoc(p, path);
	return (path);
}

static bool	strcmp_for_limiter(char *str, char *limiter)
{
	int	i;

	i = 0;
	while (str[i] && limiter[i])
	{
		if (str[i] != limiter[i])
			return (false);
		i++;
	}
	if (str[i] == '\n')
		return (true);
	return (false);
}

void	write_heredoc(t_pipex *p, char *path)
{
	int		fd;
	char	*str;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror_exit(p, path, 0);
	while (true)
	{
		write(1, "> ", 2);
		str = get_next_line(STDIN_FILENO);
		if (str == NULL || strcmp_for_limiter(str, p->argv[0]))
			break ;
		else if (str)
		{
			write(fd, str, ft_strlen(str));
			free(str);
		}
	}
	free(str);
	close(fd);
}
