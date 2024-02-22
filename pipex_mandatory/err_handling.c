/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 05:40:47 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/22 06:08:16 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	err_exit(char *s, char *cmd, char **args, int msg)
{
	if (msg == 1)
	{
		ft_putstr(s, 2);
		ft_putstr(cmd, 2);
		ft_putstr(": No such file or directory\n", 2);
		free_array(args);
	}
	else if (msg == 0)
	{
		ft_putstr(cmd, 2);
		ft_putstr(s, 2);
		free_array(args);
	}
	exit(EXIT_FAILURE);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	fatal(char *msg)
{
	ft_putstr(msg, 2);
	exit(EXIT_FAILURE);
}
