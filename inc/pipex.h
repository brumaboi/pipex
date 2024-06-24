/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:55:56 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/24 16:14:02 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"

//pipex_utils.c
void	error_and_exit(const char *message);
void	close_fds(int fd1, int fd2, int fd3, int fd4);
void	create_pipe(int *pipefd);
void	fork_process(pid_t *pid);
void	check_file_not_empty(int *file, const char *filename);

//pipex_handler.c
void	handle_child1(int file1, int *pipefd, char *cmd, char *const envp[]);
void	handle_child2(int file2, int *pipefd, char *cmd, char *const envp[]);

//path-finder.c
char	*find_command_path(const char *cmd, char *const envp[]);

//split.c
char	**split_string(const char *str, int *count);

//validate_input.c
void	validate_input(int argc, char *argv[]);

#endif