/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:46:35 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/18 18:03:23 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(t_pipex *pipex)
{
	int	i;

	if (close(pipex->infile) == -1)
		err_msg("close infile");
	if (close(pipex->outfile) == -1)
		err_msg("close outfile");
	i = 0;
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
	free(pipex->pipe);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_nmbs)
	{
		if (close(pipex->pipe[i]) == -1)
			err_msg("close");
		i++;
	}
}

int	check(char	**av, t_pipex *pipex)
{
	if (!av[1])
		err_msg("Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n");
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}
