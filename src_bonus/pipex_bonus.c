/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:32:09 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/02 01:54:52 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

int	main(int argc, char *argv[], char *const envp[])
{
	int					file1;
	int					file2;
	int					num_commands;
	int					pipefd[2];
	t_command_params	params;

	validate_input(argc, argv);
	num_commands = argc - 3;
	open_files(&file1, &file2, argv, argc);
	params.cmd_idx = 0;
	params.num_commands = num_commands;
	params.pipefd = pipefd;
	params.argv = argv;
	params.envp = envp;
	handle_commands_recursively(&params, file1, file2);
	close_fds(pipefd[0], pipefd[1], file1, file2);
	while (wait(NULL) > 0)
		;
	return (EXIT_SUCCESS);
}
