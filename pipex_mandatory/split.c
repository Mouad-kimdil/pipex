/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:12:48 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/28 18:46:31 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	countword(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && *s != '\t')
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*result;

	result = (char *)malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_free(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
}

char	**ft_help(const char *s, char c, int len, char **final)
{
	char	*start;
	int		i;

	len = countword(s, c);
	final = (char **)malloc((len + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*s == c || *s == '\t')
			s++;
		start = (char *)s;
		while (*s && *s != c && *s != '\t')
			s++;
		final[i] = ft_strndup(start, s - start);
		if (!final[i])
		{
			ft_free(final, i);
			return (NULL);
		}
		i++;
	}
	final[i] = NULL;
	return (final);
}

char	**ft_split(const char *s, char c)
{
	int		len;
	char	**final;

	final = NULL;
	len = 0;
	return (ft_help(s, c, len, final));
}
