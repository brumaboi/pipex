/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:50:00 by sbruma            #+#    #+#             */
/*   Updated: 2024/05/16 14:50:38 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Function to print an error message and exit
void	error_and_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

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
