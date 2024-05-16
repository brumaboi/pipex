/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:52:22 by sbruma            #+#    #+#             */
/*   Updated: 2024/05/16 14:59:02 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Function to handle execve
static void	execute_command(const char *cmd, char *const envp[])
{
	char	**args;

	args = malloc(4 * sizeof(char *));
	if (!args)
		error_and_exit("malloc failed");
	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = (char *)cmd;
	args[3] = NULL;
	execve("/bin/sh", args, envp);
	error_and_exit("execve failed");
}

// Function to handle the first child process
void	handle_child1(int file1, int *pipefd, char *cmd, char *const envp[])
{
	close(pipefd[0]);
	if (dup2(file1, STDIN_FILENO) == -1)
		error_and_exit("dup2 file1");
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		error_and_exit("dup2 pipefd[1]");
	close_fds(pipefd[1], file1, -1, -1);
	execute_command(cmd, envp);
}

// Function to handle the second child process
void	handle_child2(int file2, int *pipefd, char *cmd, char *const envp[])
{
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		error_and_exit("dup2 pipefd[0]");
	if (dup2(file2, STDOUT_FILENO) == -1)
		error_and_exit("dup2 file2");
	close_fds(pipefd[0], file2, -1, -1);
	execute_command(cmd, envp);
}
