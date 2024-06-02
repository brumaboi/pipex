/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:04:42 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/02 01:55:03 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

// Function to print an error message and exit
void	error_and_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

// Function to check if the file is empty
void	check_file_not_empty(int *file, const char *filename)
{
	char	buff[1];
	ssize_t	bytes;

	bytes = read(*file, buff, 1);
	if (bytes == -1)
		error_and_exit("read");
	close(*file);
	if (bytes == 0)
		error_and_exit("Error: Input file is empty");
	*file = open(filename, O_RDONLY);
	if (*file < 0)
		error_and_exit("open file1");
}
