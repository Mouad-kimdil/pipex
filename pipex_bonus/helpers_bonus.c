/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:17:56 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/28 03:28:07 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*findpath(char **env)
{
	if (!env)
		return (NULL);
	while (*env && ft_strncmp("PATH", *env, 4))
		env++;
	if (!*env || !(*env + 5))
		return (NULL);
	return (*env + 5);
}

void	get_infile(char **av, t_pipex *pipex)
{
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
		here_doc(av[2], pipex);
	else
	{
		pipex->infile = open(av[1], O_RDONLY, 0644);
		if (pipex->infile < 0)
			err_msg2("bash: ", av[1], ": No such file or directory\n");
	}
}

void	get_outfile(char **av, int ac, t_pipex *pipex)
{
	if (pipex->here_doc == 1)
		pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->outfile = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->outfile < 0)
		err_msg("open");
}

char	*check_access(char **path, char *cmd)
{
	char	*tmp;
	char	*full_cmd;
	char	**temp;

	if (*cmd == '/' || *cmd == '.')
	{
		temp = ft_split(cmd, '/');
		if (temp[1] == NULL)
			return (err_msg2("bash: ", cmd, ": No such file or directory")
				, free_array(temp), NULL);
		if (access(cmd, X_OK) == 0)
			return (cmd);
	}
	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		full_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_cmd, X_OK) == 0)
			return (full_cmd);
		free(full_cmd);
		path++;
	}
	return (NULL);
}

void	here_doc(char *delimiter, t_pipex *pipex)
{
	char	*tmp;
	int		fd;

	fd = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		err_msg("open");
	while (1)
	{
		write(1, ">> ", 2);
		tmp = get_next_line(0);
		if (!tmp || ((ft_strncmp(tmp, delimiter, ft_strlen(delimiter)) == 0)
				&& (ft_strlen(tmp) - 1 == ft_strlen(delimiter))))
			break ;
		write(fd, tmp, ft_strlen(tmp));
		free(tmp);
	}
	if (*delimiter == '\n')
		free(delimiter);
	free(tmp);
	close(fd);
	pipex->infile = open("heredoc", O_RDONLY);
	unlink("heredoc");
	if (pipex->infile < 0)
		err_msg("open");
}
