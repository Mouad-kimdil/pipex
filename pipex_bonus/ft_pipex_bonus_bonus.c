/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:16:45 by mkimdil           #+#    #+#             */
/*   Updated: 2024/01/13 20:11:22 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < check(av, &pipex))
		err_msg3(pipex);
	get_infile(av, &pipex);
	get_outfile(av, ac, &pipex);
	pipex.cmd_nmbs = ac - 3 - pipex.here_doc;
	pipex.pipe_nmbs = 2 * (pipex.cmd_nmbs - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_nmbs);
	if (!pipex.pipe)
		err_msg("pipe err");
	pipex.env_path = findpath(env);
	pipex.cmd_paths = ft_split(pipex.env_path, ':');
	if (!pipex.cmd_paths)
		main_free(&pipex);
	creat_pipes(&pipex);
	pipex.idx = -1;
	while (++pipex.idx < pipex.cmd_nmbs)
		child(pipex, av, env);
	close_pipes(&pipex);
	while (wait(NULL) != -1)
		;
	free_all(&pipex);
	exit(EXIT_SUCCESS);
}
