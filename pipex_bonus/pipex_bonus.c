/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:16:45 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/18 18:03:42 by mkimdil          ###   ########.fr       */
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
	intialize_vars(&pipex, ac, env);
	if (!pipex.pipe)
		err_msg("pipe err");
	if (!pipex.cmd_paths)
		main_free(&pipex);
	creat_pipes(&pipex);
	while (++pipex.idx < pipex.cmd_nmbs)
	{
		child(pipex, av, env);
		if (ft_strncmp(av[1 + pipex.idx + pipex.here_doc], "", 2) == 0
			&& ft_strncmp(av[1], "here_doc", 9) != 0)
			err_msg2("Command ", "''", " not found\n");
	}
	close_pipes(&pipex);
	while (wait(NULL) != -1)
		;
	free_all(&pipex);
	exit(EXIT_SUCCESS);
}
