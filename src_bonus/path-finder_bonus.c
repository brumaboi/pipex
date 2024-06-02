/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path-finder_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:09:57 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/02 01:54:56 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

static const char	*get_path_from_envp(char *const envp[])
{
	const char	*path;

	path = NULL;
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = *envp + 5;
			break ;
		}
		envp++;
	}
	if (!path)
	{
		error_and_exit("PATH not found in environment");
	}
	return (path);
}

static char	*duplicate_string(const char *str)
{
	char	*copy;

	copy = ft_strdup(str);
	if (!copy)
	{
		error_and_exit("strdup failed");
	}
	return (copy);
}

static char	*build_full_path(const char *start, const char *cmd)
{
	char	*full_path;
	size_t	len;

	len = ft_strlen(start) + strlen(cmd) + 2;
	full_path = (char *)malloc(len);
	if (!full_path)
	{
		error_and_exit("malloc failed");
	}
	ft_strcpy(full_path, start);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, cmd);
	if (access(full_path, X_OK) == 0)
	{
		return (full_path);
	}
	free(full_path);
	return (NULL);
}

static char	*search_paths(char *path_copy, const char *cmd)
{
	char	*start;
	char	*end;
	char	*full_path;

	start = path_copy;
	while (ft_strchr(start, ':') != NULL)
	{
		end = ft_strchr(start, ':');
		*end = '\0';
		if (*start != '\0')
		{
			full_path = build_full_path(start, cmd);
			if (full_path)
			{
				return (full_path);
			}
		}
		start = end + 1;
	}
	if (*start != '\0')
	{
		return (build_full_path(start, cmd));
	}
	return (NULL);
}

char	*find_command_path(const char *cmd, char *const envp[])
{
	const char	*path;
	char		*path_copy;
	char		*result;

	path = get_path_from_envp(envp);
	path_copy = duplicate_string(path);
	result = search_paths(path_copy, cmd);
	free(path_copy);
	return (result);
}
