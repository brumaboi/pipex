/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:18:34 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/24 15:42:00 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Recursive function to count double quotes in a string
static int	count_double_quotes(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '"')
		return (1 + count_double_quotes(str + 1));
	return (count_double_quotes(str + 1));
}

// Function to validate if an argument is empty or just spaces
static int	is_empty_argument(const char *str)
{
	while (*str)
	{
		if (!ft_isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

// Recursive function to validate arguments
static void	validate_commands(char *cmd1, char *cmd2)
{
	if (is_empty_argument(cmd1))
		error_and_exit("Invalid command: cmd1 cannot be empty.");
	if (is_empty_argument(cmd2))
		error_and_exit("Invalid command: cmd2 cannot be empty.");
	if (count_double_quotes(cmd1) % 2 != 0)
		error_and_exit("Invalid syntax: unbalanced double quotes in cmd1.");
	if (count_double_quotes(cmd2) % 2 != 0)
		error_and_exit("Invalid syntax: unbalanced double quotes in cmd2.");
}

// Function to validate input arguments recursively
void	validate_input(int argc, char *argv[])
{
	if (argc != 5)
		error_and_exit("usage: ./pipex file1 cmd1 cmd2 file2");
	if (is_empty_argument(argv[1]))
		error_and_exit("Invalid input file: input file cannot be empty.");
	if (is_empty_argument(argv[4]))
		error_and_exit("Invalid output file: output file cannot be empty.");
	validate_commands(argv[2], argv[3]);
}
