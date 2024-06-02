/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:53:04 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/02 01:54:02 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

// Recursive function to count double quotes in a string
static int	count_double_quotes(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '"')
		return (1 + count_double_quotes(str + 1));
	return (count_double_quotes(str + 1));
}

// Function to validate if a command is empty or just spaces
static int	is_empty_command(const char *str)
{
	while (*str)
	{
		if (!ft_isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

// Recursive function to validate commands
static void	validate_commands(int argc, char *argv[], int idx)
{
	int	quote_count;

	if (idx >= argc - 1)
		return ;
	if (is_empty_command(argv[idx]))
		error_and_exit("Invalid command: command cannot be empty.");
	quote_count = count_double_quotes(argv[idx]);
	if (quote_count % 2 != 0)
		error_and_exit("Invalid syntax: unbalanced double quotes in commands.");
	validate_commands(argc, argv, idx + 1);
}

// Function to validate input arguments recursively
void	validate_input(int argc, char *argv[])
{
	if (argc < 5)
		error_and_exit("usage: ./pipex file1 cmd1 ... cmdN file2");
	if (is_empty_command(argv[1]))
		error_and_exit("Invalid input file: input file cannot be empty.");
	if (is_empty_command(argv[argc - 1]))
		error_and_exit("Invalid output file: output file cannot be empty.");
	validate_commands(argc, argv, 2);
}
