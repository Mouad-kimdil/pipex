/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:08:25 by mkimdil           #+#    #+#             */
/*   Updated: 2024/01/14 10:39:23 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	creat_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nmbs - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			free_all(pipex);
		i++;
	}
}

void	sub_dup2(int fd1, int fd2)
{
	if (dup2(fd1, 0) == -1)
		err_msg("dup");
	if (dup2(fd2, 1) == -1)
		err_msg("dup");
}

void	child(t_pipex p, char **av, char **env)
{
	p.pid = fork();
	if (p.pid == -1)
		err_msg("fork");
	if (p.pid == 0)
	{
		if (p.idx == 0)
			sub_dup2(p.infile, p.pipe[1]);
		else if (p.idx == p.cmd_nmbs - 1)
			sub_dup2(p.pipe[2 * p.idx - 2], p.outfile);
		else
			sub_dup2(p.pipe[2 * p.idx - 2], p.pipe[2 * p.idx + 1]);
		close_pipes(&p);
		p.cmd_args = ft_split(av[2 + p.idx + p.here_doc], ' ');
		p.cmd = check_access(p.cmd_paths, p.cmd_args[0]);
		if (!p.cmd)
		{
			child_free(&p);
			err_msg(p.cmd_args[0]);
		}
		if (execve(p.cmd, p.cmd_args, env) == -1)
			err_msg("execve error");
	}
}
