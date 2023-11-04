/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:22:05 by yoda              #+#    #+#             */
/*   Updated: 2023/11/04 04:20:55 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_heredoc(t_pipex *p, char *limiter);

static void	file_if_readable(char *file)
{
	if (access(file, F_OK) != 0)
		perror_exit(NULL, file, 0);
	if (access(file, R_OK) != 0)
		perror_exit(NULL, file, 0);
}

static void	file_if_writable(char *file)
{
	if (access(file, F_OK) == -1)
		return ;
	else if (access(file, W_OK) != 0)
		perror_exit(NULL, file, 0);
}

int	arg_check_files(int c, char **v, t_pipex *p)
{
	int	flag;

	if (!p->here_doc)
		file_if_readable(v[0]);
	file_if_writable(v[c - 1]);
	if (p->here_doc)
		p->infile = handle_heredoc(p, v[0]);
	else
		p->infile = open(v[0], O_RDONLY);
	if (p->infile == -1)
		perror_exit(NULL, v[0], 0);
	if (p->here_doc)
		flag = O_WRONLY | O_CREAT | O_APPEND;
	else
		flag = O_WRONLY | O_CREAT | O_TRUNC;
	p->outfile = open(v[c - 1], flag, 0644);
	if (p->outfile == -1)
		perror_exit(p, v[c - 1], 0);
	return (TRUE);
}

static int	strcmp_for_limiter(char *str, char *limiter)
{
	int	i;

	i = 0;
	while (str[i] && limiter[i])
	{
		if (str[i] != limiter[i])
			return (FALSE);
		i++;
	}
	if (str[i] == '\n')
		return (TRUE);
	return (FALSE);
}

int	handle_heredoc(t_pipex *p, char *limiter)
{
	int		fd;
	char	*str;

	fd = open("./tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror_exit(p, "./tmp", 0);
	while (TRUE)
	{
		write(1, "heredoc> ", 9);
		str = get_next_line(STDIN_FILENO);
		if (strcmp_for_limiter(str, limiter))
			break ;
		else if (str)
		{
			write(fd, str, ft_strlen(str));
			free(str);
		}
	}
	free(str);
	close(fd);
	fd = open("./tmp", O_RDONLY);
	if (fd == -1)
		perror_exit(p, "./tmp", 0);
	return (fd);
}
