/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:27:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/29 19:35:02 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	path_check(char *path, t_shell *shell)
{
	if (path[0] == '.' && path[1] == '/' && ft_strlen(path) == 2)
		return (no_such_file_or_folder(shell->trimmed_prompt, shell), FALSE);
	if (path[0] == '.' || path[0] == '/')
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
	}
	return (FALSE);
}

int	no_such_file_or_folder(char *command, t_shell *shell)
{
	p_err("%s%s: %s\n", SHELL, command, strerror(ENOENT));
	shell->exit_code = 127;
	return (FALSE);
}
