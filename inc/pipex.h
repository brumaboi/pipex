/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:55:56 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/01 23:47:57 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"

void	error_and_exit(const char *message);
void	close_fds(int fd1, int fd2, int fd3, int fd4);
void	create_pipe(int *pipefd);
void	fork_process(pid_t *pid);
void	handle_child1(int file1, int *pipefd, char *cmd, char *const envp[]);
void	handle_child2(int file2, int *pipefd, char *cmd, char *const envp[]);
void	check_file_not_empty(int *file, const char *filename);
char	*find_command_path(const char *cmd, char *const envp[]);
char	**split_string(const char *str, int *count);
void	validate_input(int argc, char *argv[]);

#endif