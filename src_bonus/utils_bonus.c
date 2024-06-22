/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:08:47 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/22 23:22:36 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

// Function to close multiple file descriptors
void	close_fds(int fd1, int fd2, int fd3, int fd4)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
	if (fd3 >= 0)
		close(fd3);
	if (fd4 >= 0)
		close(fd4);
}

// Function to create a pipe and handle errors
void	create_pipe(int *pipefd)
{
	if (pipe(pipefd) == -1)
		error_and_exit("pipe");
}

// Function to fork a process and handle errors
void	fork_process(pid_t *pid)
{
	*pid = fork();
	if (*pid < 0)
		error_and_exit("fork");
}

// Function to open files
void	open_files(int *file1, int *file2, char **argv, int argc)
{
	*file1 = open(argv[1], O_RDONLY);
	if (*file1 < 0)
		error_and_exit("open file1");
	check_file_not_empty(file1, argv[1]);
	*file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (*file2 < 0)
		error_and_exit("open file2");
}
