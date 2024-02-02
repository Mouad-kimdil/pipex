/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 05:40:47 by mkimdil           #+#    #+#             */
/*   Updated: 2024/01/08 18:31:21 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	err_exit(char *s, char *cmd, char **args)
{
	ft_putstr(s, 2);
	ft_putstr(cmd, 2);
	write(2, "\n", 1);
	free_array(args);
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
	perror(msg);
	exit(EXIT_FAILURE);
}
