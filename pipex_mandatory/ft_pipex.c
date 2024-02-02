/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:17:50 by mkimdil           #+#    #+#             */
/*   Updated: 2024/01/23 16:08:05 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *fds, char **av, char **env)
{
	int		fd;
	char	**tmp;
	char	*path;
	char	**args;

	args = ft_split(av[3], ' ');
	tmp = ft_split(findpath(env), ':');
	path = check_access(tmp, args[0]);
	free_array(tmp);
	if (!path)
		err_exit("zsh: command not found: ", args[0], args);
	fd = open(av[4], O_RDWR | O_CREAT, 0666);
	if (fd == -1)
		err_exit("zsh: no such file or directory: ", av[4], args);
	sub_dup2(fds, fd, 1);
	if (execve(path, args, env) == -1)
		err_exit("zsh: command not found: ", args[0], args);
	exit(EXIT_FAILURE);
}

void	parent(int *fds, char **av, char **env)
{
	int		fd;
	char	**tmp;
	char	**args;
	char	*path;

	args = ft_split(av[2], ' ');
	tmp = ft_split(findpath(env), ':');
	path = check_access(tmp, args[0]);
	free_array(tmp);
	if (!path)
		err_exit("zsh: command not found: ", args[0], args);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		err_exit("zsh: no such file or directory: ", av[1], args);
	sub_dup2(fds, fd, 0);
	if (execve(path, args, env) == -1)
		err_exit("zsh: command not found: ", args[0], args);
	exit(EXIT_FAILURE);
}

void	ft_pipex(char **av, char **env)
{
	int	fds[2];
	int	pid1;
	int	pid2;

	if (pipe(fds) == -1)
		fatal("pipe");
	pid1 = fork();
	if (pid1 == -1)
		fatal("fork_1");
	if (pid1 == 0)
		child(fds, av, env);
	pid2 = fork();
	if (pid2 == -1)
		fatal("fork_2");
	if (pid2 == 0)
		parent(fds, av, env);
	if (close(fds[0]) == -1 || close(fds[1]) == -1)
		fatal("close 7");
	while (wait(NULL) != -1)
		;
}

int	main(int ac, char *av[], char **env)
{
	if (ac != 5)
	{
		ft_putstr("Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_pipex(av, env);
	return (EXIT_SUCCESS);
}
