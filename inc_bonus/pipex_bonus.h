/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:02:16 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/22 21:33:39 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/inc/libft.h"

typedef struct s_command_params
{
	int			cmd_idx;
	int			num_commands;
	int			*pipefd;
	char		**argv;
	char *const	*envp;
}	t_command_params;

//error_bonus.c
void	error_and_exit(const char *message);
void	check_file_not_empty(int *file, const char *filename);

//handle_bonus.c
void	handle_commands_recursively(t_command_params *params,
			int in_fd, int out_fd);

//split_bonus.c
char	**split_string(const char *str, int *count);

//utils_bonus.c
void	close_fds(int fd1, int fd2, int fd3, int fd4);
void	create_pipe(int *pipefd);
void	fork_process(pid_t *pid);
void	open_files(int *file1, int *file2, char **argv, int argc);

//path-finder_bonus.c
char	*find_command_path(const char *cmd, char *const envp[]);

//validate_input_bonus.c
void	validate_input(int argc, char *argv[]);

//here_doc.c
void	handle_here_doc_commands(t_command_params *params, int out_fd,
			const char *limiter);
void	open_files_for_here_doc(int *file1, int *file2, char **argv, int argc);
#endif