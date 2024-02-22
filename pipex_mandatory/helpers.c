/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:14:59 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/22 06:00:10 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access(char **path, char *cmd)
{
	char	*tmp;
	char	*full_cmd;
	char	**temp;

	if (*cmd == '/' || *cmd == '.')
	{
		temp = ft_split(cmd, '/');
		if (temp[1] == NULL)
			return (free_array(temp), NULL);
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

void	sub_dup2(int *fds, int fd, int state)
{
	if (state == 0)
	{
		close(fds[0]);
		if (dup2(fd, 0) == -1)
			fatal("dup 1");
		if (dup2(fds[1], 1) == -1)
			fatal("dup 2");
		if (close(fd) == -1 || close(fds[1]) == -1)
			fatal("close");
	}
	else if (state == 1)
	{
		close(fds[1]);
		if (dup2(fd, 1) == -1)
			fatal("dup 3");
		if (dup2(fds[0], 0) == -1)
			fatal("dup 4");
		if (close(fd) == -1 || close(fds[0]) == -1)
			fatal("close");
	}
}

char	*findpath(char **env)
{
	while (ft_strncmp("PATH", *env, 4) != 0)
		env++;
	return (*env + 5);
}
