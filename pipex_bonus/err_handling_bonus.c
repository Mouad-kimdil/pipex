/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:46:58 by mkimdil           #+#    #+#             */
/*   Updated: 2024/01/13 12:12:19 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	err_msg(char *msg)
{
	ft_putstr(msg, 2);
	exit(EXIT_FAILURE);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	err_msg2(char *s, char *cmd)
{
	ft_putstr(s, 2);
	ft_putstr(cmd, 2);
	ft_putstr("\n", 2);
	exit(EXIT_FAILURE);
}

void	err_msg3(t_pipex pipex)
{
	if (pipex.here_doc == 1)
	{
		ft_putstr("Usage: ./pipex here_doc LIMITER cmd cmd1 file", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr("Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2", 2);
		exit(EXIT_FAILURE);
	}
}

void	main_free(t_pipex *pipex)
{
	if (pipex->here_doc == 1)
		if (unlink("heredoc") == -1)
			err_msg("unlink");
	if (close(pipex->infile) == -1)
		err_msg("close");
	if (close(pipex->outfile) == -1)
		err_msg("close");
	free(pipex->pipe);
	exit(EXIT_FAILURE);
}
