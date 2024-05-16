/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:55:56 by sbruma            #+#    #+#             */
/*   Updated: 2024/05/16 11:32:12 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"

int	handle_child_process(char **argv, int *fd, char *envp[]);
int	handle_parent_process(char **argv, int *fd, int pid, char *envp[]);
int	validate_args(int argc);
int	create_pipe(int *fd);

#endif