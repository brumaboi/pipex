/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:59:24 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/02 02:05:00 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

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

// Function to handle each child process
static void	handle_child(int in_fd, int out_fd, char *cmd, char *const envp[])
{
	if (dup2(in_fd, STDIN_FILENO) == -1)
		error_and_exit("dup2 in_fd");
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		error_and_exit("dup2 out_fd");
	close_fds(in_fd, out_fd, -1, -1);
	execute_command(cmd, envp);
}

// Recursive function to handle commands
void	handle_commands_recursively(t_command_params *params,
	int in_fd, int out_fd)
{
	pid_t	pid;

	if (params->cmd_idx == params->num_commands - 1)
	{
		fork_process(&pid);
		if (pid == 0)
		{
			handle_child(in_fd, out_fd, params->argv[params->cmd_idx + 2],
				params->envp);
		}
	}
	else
	{
		create_pipe(params->pipefd);
		fork_process(&pid);
		if (pid == 0)
		{
			close(params->pipefd[0]);
			handle_child(in_fd, params->pipefd[1],
				params->argv[params->cmd_idx + 2], params->envp);
		}
		close(params->pipefd[1]);
		params->cmd_idx++;
		handle_commands_recursively(params, params->pipefd[0], out_fd);
	}
}
