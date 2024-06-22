/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:52:22 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/02 20:50:43 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Function to handle execve
static void	execute_command(const char *cmd, char *const envp[])
{
	int		arg_count;
	char	**args;
	char	*cmd_path;
	int		i;

	args = split_string(cmd, &arg_count);
	if (!args)
		error_and_exit("split_string");
	cmd_path = find_command_path(args[0], envp);
	if (!cmd_path)
	{
		i = 0;
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
		error_and_exit("Command not found");
	}
	execve(cmd_path, args, envp);
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
