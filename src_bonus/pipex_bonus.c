/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:32:09 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/24 15:34:35 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	process_here_doc(t_command_params *params, int argc,
			int *file1, int *file2)
{
	open_files_for_here_doc(file1, file2, params->argv, argc);
	handle_here_doc_commands(params, *file2, params->argv[2]);
}

void	process_standard_input(t_command_params *params,
			int argc, int *file1, int *file2)
{
	open_files(file1, file2, params->argv, argc);
	handle_commands_recursively(params, *file1, *file2);
}

// Main function
int	main(int argc, char *argv[], char *const envp[])
{
	int					file1;
	int					file2;
	int					pipefd[2];
	t_command_params	params;

	validate_input(argc, argv);
	params.cmd_idx = 0;
	params.pipefd = pipefd;
	params.argv = argv;
	params.envp = envp;
	params.num_commands = argc - 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		process_here_doc(&params, argc, &file1, &file2);
	else
		process_standard_input(&params, argc, &file1, &file2);
	close_fds(pipefd[0], pipefd[1], file1, file2);
	waitpid(-1, NULL, 0);
	return (0);
}
