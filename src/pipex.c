/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:09 by sbruma            #+#    #+#             */
/*   Updated: 2024/05/20 22:14:04 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	open_files(int *file1, int *file2, char **argv)
{
	*file1 = open(argv[1], O_RDONLY);
	if (*file1 < 0)
		error_and_exit("open file1");
	check_file_not_empty(file1, argv[1]);
	*file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*file2 < 0)
		error_and_exit("open file2");
}

int	main(int argc, char *argv[], char *envp[])
{
	int		file1;
	int		file2;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_and_exit("usage: ./pipex file1 cmd1 cmd2 file2");
	open_files(&file1, &file2, argv);
	create_pipe(pipefd);
	fork_process(&pid1);
	if (pid1 == 0)
		handle_child1(file1, pipefd, argv[2], envp);
	fork_process(&pid2);
	if (pid2 == 0)
		handle_child2(file2, pipefd, argv[3], envp);
	close_fds(pipefd[0], pipefd[1], file1, file2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (EXIT_SUCCESS);
}
