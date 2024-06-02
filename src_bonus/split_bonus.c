/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:08:03 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/02 01:54:49 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

static const char	*find_token_end(const char *start)
{
	int	in_single_quote;
	int	in_double_quote;

	in_single_quote = 0;
	in_double_quote = 0;
	while (*start && (in_single_quote || in_double_quote
			|| !ft_isspace(*start)))
	{
		if (*start == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		else if (*start == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		start++;
	}
	return (start);
}

static int	count_spaces(const char *str)
{
	int	spaces;
	int	in_single_quote;
	int	in_double_quote;

	spaces = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	while (*str)
	{
		if (*str == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		else if (*str == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (ft_isspace(*str) && !in_single_quote && !in_double_quote)
			spaces++;
		str++;
	}
	return (spaces);
}

static char	*allocate_and_copy(const char *start, const char *end)
{
	char	*result;
	int		in_single_quote;
	int		in_double_quote;
	int		i;

	in_single_quote = 0;
	in_double_quote = 0;
	i = 0;
	result = malloc((end - start + 1) * sizeof(char));
	if (!result)
		error_and_exit("malloc");
	while (start < end)
	{
		if (*start == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (*start == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		else
			result[i++] = *start;
		start++;
	}
	result[i] = '\0';
	return (result);
}

char	**split_string(const char *str, int *count)
{
	int			spaces;
	char		**result;
	int			idx;
	const char	*end;

	idx = 0;
	spaces = count_spaces(str);
	result = malloc((spaces + 2) * sizeof(char *));
	if (!result)
		error_and_exit("malloc");
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str)
		{
			end = find_token_end(str);
			result[idx++] = allocate_and_copy(str, end);
			str = end;
		}
	}
	result[idx] = NULL;
	*count = idx;
	return (result);
}
