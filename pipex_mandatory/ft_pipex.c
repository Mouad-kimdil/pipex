/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:17:50 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/22 06:11:26 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_1(int *fds, char **av, char **env)
{
	int		fd;
	char	**tmp;
	char	*path;
	char	**args;

	args = ft_split(av[3], ' ');
	if (!args[0])
		fatal("command not found");
	tmp = ft_split(findpath(env), ':');
	path = check_access(tmp, args[0]);
	free_array(tmp);
	if (!path)
		err_exit(": command not found\n", args[0], args, 0);
	fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		err_exit("bash: ", av[4], args, 1);
	sub_dup2(fds, fd, 1);
	if (execve(path, args, env) == -1)
		err_exit(": command not found\n", args[0], args, 0);
	exit(EXIT_FAILURE);
}

static void	child_2(int *fds, char **av, char **env)
{
	int		fd;
	char	**tmp;
	char	**args;
	char	*path;

	args = ft_split(av[2], ' ');
	if (!args[0])
		fatal("command not found");
	tmp = ft_split(findpath(env), ':');
	path = check_access(tmp, args[0]);
	if (!path)
		err_exit(": command not found\n", args[0], args, 0);
	free_array(tmp);
	if (!path)
		err_exit(": command not found\n", args[0], args, 0);
	fd = open(av[1], O_RDONLY, 0644);
	if (fd == -1)
		err_exit("bash: ", av[1], args, 1);
	sub_dup2(fds, fd, 0);
	if (execve(path, args, env) == -1)
		err_exit(": command not found\n", args[0], args, 0);
	exit(EXIT_FAILURE);
}

static void	ft_pipex(char **av, char **env, int *state)
{
	int	fds[2];
	int	pid1;
	int	pid2;
	if (pipe(fds) == -1)
		fatal("pipe");
	pid1 = fork();
	if (pid1 == -1)
		fatal("fork");
	if (pid1 == 0)
		child_1(fds, av, env);
	pid2 = fork();
	if (pid2 == -1)
		fatal("fork");
	if (pid2 == 0)
		child_2(fds, av, env);
	if (close(fds[0]) == -1 || close(fds[1]) == -1)
		fatal("close");
	waitpid(pid2, state, 0);
	exit(*state);
}

int	main(int ac, char *av[], char **env)
{
	int	state;

	if (ac != 5 || !env || !*env)
	{
		ft_putstr("Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]\n", 2);
		exit(EXIT_FAILURE);
	}
	state = 0;
	ft_pipex(av, env, &state);
	exit(state);
}
