/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:32:09 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/22 22:34:57 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

// Main function
int	main(int argc, char *argv[], char *const envp[])
{
	int					file1;
	int					file2;
	int					num_commands;
	int					pipefd[2];
	t_command_params	params;

	if (argc < 5)
		error_and_exit("usage: ./pipex file1 cmd1 ... cmdN file2");
	validate_input(argc, argv);
	num_commands = argc - 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		num_commands = argc - 4;
		open_files_for_here_doc(&file1, &file2, argv, argc);
	}
	else
		open_files(&file1, &file2, argv, argc);
	params.cmd_idx = 0;
	params.num_commands = num_commands;
	params.pipefd = pipefd;
	params.argv = argv;
	params.envp = envp;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		handle_here_doc_commands(&params, file2, argv[2]);
	else
		handle_commands_recursively(&params, file1, file2);
	close_fds(pipefd[0], pipefd[1], file1, file2);
	while (wait(NULL) > 0)
		;
	return (0);
}
