/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:07:47 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/18 18:03:30 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	line = ft_calloc((ft_strlen(buffer) - i + 1), 1);
	if (!line)
		return (free(line), free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	return (free(buffer), line);
}

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		line;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer || !res)
		return (free(res), free(buffer), NULL);
	line = 1;
	while (line > 0)
	{
		line = read(fd, buffer, BUFFER_SIZE);
		if (line == -1)
			return (free(res), free(buffer), NULL);
		buffer[line] = '\0';
		res = ft_join(res, buffer);
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), res);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(line), free(buffer), NULL);
	line[i] = '\0';
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*ft_join(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}
