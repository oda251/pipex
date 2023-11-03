/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:07:19 by yoda              #+#    #+#             */
/*   Updated: 2023/11/03 21:25:13 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		open_files(int c, char **v, t_pipex *p);
void	handle_heredoc(t_pipex *p, char *limiter);

int	main(int c, char **v, char **envp)
{
	t_pipex	p;

	if (c < 5)
		error_invalid_usage();
	v++;
	c--;
	ini_pipex(&p, envp);
	has_here_doc(&c, &v, &p);
	if (c < 4)
		error_invalid_usage();
	arg_check_files(c, v, p.here_doc);
	p.args = trans_args(c - 2, v + 1);
	if (!p.args)
		perror_exit(NULL, NULL, 0);
	arg_check_cmds(envp, p);
	if (!open_files(c, v, &p))
	{
		ft_free_char_triple_p(p.args);
		perror_exit(NULL, NULL, 0);
	}
	pipex(&p);
	free_pipex(&p);
	return (0);
}

int	open_files(int c, char **v, t_pipex *p)
{
	p->infile = NONE;
	p->outfile = NONE;
	if (!p->here_doc)
	{
		p->infile = open(v[0], O_RDONLY);
		if (p->infile == -1)
			return (FALSE);
		p->outfile = open(v[c - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (p->outfile == -1)
			return (FALSE);
	}
	else
	{
		handle_heredoc(p, v[0]);
		if (p->infile == -1)
			return (FALSE);
		p->outfile = open(v[c - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (p->outfile == -1)
			return (FALSE);
	}
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

void	handle_heredoc(t_pipex *p, char *limiter)
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
	p->infile = open("./tmp", O_RDONLY);
}
