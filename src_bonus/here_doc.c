/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:02:01 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/17 17:02:01 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

static void	read_and_write_lines(int write_fd, const char *limiter)
{
	char	*line;

	write(STDOUT_FILENO, "> ", 2);
	line = get_next_line(STDIN_FILENO);
	if (!line)
		error_and_exit("get_next_line failed");
	if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
		&& line[ft_strlen(limiter)] == '\n')
	{
		free(line);
		return ;
	}
	write(write_fd, line, ft_strlen(line));
	free(line);
	read_and_write_lines(write_fd, limiter);
}

static void	handle_child_process(int *pipefd, const char *limiter)
{
	close(pipefd[0]);
	read_and_write_lines(pipefd[1], limiter);
	close(pipefd[1]);
	exit(0);
}

static void	handle_parent_process(t_command_params *params,
			int *pipefd, int out_fd, pid_t child_pid)
{
	close(pipefd[1]);
	waitpid(child_pid, NULL, 0);
	params->cmd_idx++;
	handle_commands_recursively(params, pipefd[0], out_fd);
	close(pipefd[0]);
}

void	handle_here_doc_commands(t_command_params *params,
			int out_fd, const char *limiter)
{
	pid_t	pid;
	int		pipefd[2];

	create_pipe(pipefd);
	fork_process(&pid);
	if (pid == 0)
		handle_child_process(pipefd, limiter);
	else
		handle_parent_process(params, pipefd, out_fd, pid);
}
