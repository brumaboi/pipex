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

// Function to open files for here_doc
void	open_files_for_here_doc(int *file1, int *file2, char **argv, int argc)
{
	*file1 = STDIN_FILENO;
	*file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*file2 < 0)
		error_and_exit("open file2");
}

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
			int *pipefd, int out_fd)
{
	close(pipefd[1]);
	wait(NULL);
	params->cmd_idx++;
	handle_commands_recursively(params, pipefd[0], out_fd);
	close(pipefd[0]);
}

void	handle_here_doc_commands(t_command_params *params,
			int out_fd, const char *limiter)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		error_and_exit("pipe failed");
	pid = fork();
	if (pid == -1)
		error_and_exit("fork failed");
	if (pid == 0)
		handle_child_process(pipefd, limiter);
	else
		handle_parent_process(params, pipefd, out_fd);
}
