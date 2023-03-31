/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:27:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 08:09:50 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	path_check(char *path, t_shell *shell)
{
	if (path[0] == '.' && path[1] == '.' && path[2] == '/')
	{
		if (access(path, X_OK) == 0)
			return (TRUE);
		else
			return (no_such_file_or_folder(path, shell), FALSE);
	}
	if (path[0] == '.' && path[1] == '/' && ft_strlen(path) == 2)
		return (no_such_file_or_folder(shell->trimmed_prompt, shell), FALSE);
	if (path[0] == '.' || path[0] == '/' || path)
	{
		if (path[0] == '.' && path[1] != '/')
			return (invalid_command(shell, path), FALSE);
		else if (path[0] == '.')
		{
			if (path[0] == '.' && access(path, X_OK) == 0)
				return (TRUE);
			return (no_such_file_or_folder(path, shell), FALSE);
		}
		else if (path[0] == '/')
		{
			if (access(path, X_OK) == 0)
				return (TRUE);
			else
				return (no_such_file_or_folder(path, shell), FALSE);
		}
		else if (access(path, X_OK) == 0)
			return (TRUE);
		else if (shell->envless == TRUE)
			return (no_such_file_or_folder(path, shell), FALSE);
	}
	return (FALSE);
}

int	no_such_file_or_folder(char *command, t_shell *shell)
{
	shell->exit_code = 127;
	p_err("%s%s: %s\n", SHELL, command, strerror(ENOENT));
	return (FALSE);
}
