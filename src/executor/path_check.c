/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:27:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/19 00:13:37 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	path_with_bin_check(char **commands)
{
	if (*commands[0] == '/')
	{
		if (ft_strncmp(*commands, "/bin", 4) == 0)
		{
			if (path_check(commands[0]) == TRUE)
				return (TRUE);
			else if (no_such_file_or_folder(*commands) == FALSE)
				return (FALSE);
		}
		if (ft_strncmp(*commands, "/usr/bin", 8) == 0)
		{
			if (path_check(commands[0]) == TRUE)
				return (TRUE);
			else if (no_such_file_or_folder(*commands) == FALSE)
				return (FALSE);
		}
		else if (no_such_file_or_folder(*commands) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int	path_check(char *cmd_path)
{
	if (cmd_path[0] == '/' && access(cmd_path, X_OK) == 0)
		return (TRUE);
	return (FALSE);
}

int	no_such_file_or_folder(char *command)
{
	ft_printf("./pipex: %s: %s\n", strerror(ENOENT), command);
	return (FALSE);
}
