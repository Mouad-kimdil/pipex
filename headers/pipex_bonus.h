/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:16:50 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/18 14:02:39 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	pid_t	pid;
	int		here_doc;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		idx;
}	t_pipex;

int		countword(const char *s, char c);
char	*ft_strndup(const char *src, int n);
void	ft_free(char **ptr, int i);
char	**ft_help(const char *s, char c, int len, char **final);
char	**ft_split(const char *s, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, int len);
void	ft_putstr(char *str, int fd);
char	*findpath(char **env);
void	err_msg(char *msg);
void	get_infile(char **av, t_pipex *pipe);
void	get_outfile(char **av, int ac, t_pipex *pipe);
char	*check_access(char **path, char *cmd);
void	child(t_pipex pipex, char **argv, char **envp);
void	creat_pipes(t_pipex *pipex);
void	free_all(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	err_msg2(char *s, char *cmd, char *s2);
void	free_array(char **arr);
void	sub_dup2(int fd1, int fd2);
void	main_free(t_pipex *pipex);
int		check(char	**av, t_pipex *pipex);
void	err_msg3(t_pipex pipex);
char	*ft_join(char *buffer, char *buf);
char	*ft_next_line(char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_read_file(int fd, char *res);
char	*get_next_line(int fd);
char	*ft_strrchr(char *str, int c);
void	*ft_calloc(size_t count, size_t size);
void	here_doc(char *delimiter, t_pipex *pipex);
void	intialize_vars(t_pipex *pipex, int ac, char **env);

#endif