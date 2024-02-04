/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:11:17 by mkimdil           #+#    #+#             */
/*   Updated: 2024/01/08 18:04:45 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

int		countword(const char *s, char c);
char	*ft_strndup(const char *src, int n);
void	ft_free(char **ptr, int i);
char	**ft_help(const char *s, char c, int len, char **final);
char	**ft_split(const char *s, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*findpath(char **env);
void	ft_putstr(char *str, int fd);
int		err_exit(char *s, char *cmd, char **args, int msg);
void	free_array(char **str);
void	fatal(char *msg);
char	*check_access(char **path, char *cmd);
int		ft_strncmp(const char *s1, const char *s2, int len);
void	sub_dup2(int *fds, int fd, int state);

#endif
