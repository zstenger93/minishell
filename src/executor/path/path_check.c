/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:27:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 19:38:09 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	path_check(char *path, t_shell *shell)
{
	if (path[0] == '.' && path[1] == '.' && path[2] == '/'
		&& dot_dot_slash_at_path_start(shell, path) == TRUE)
		return (TRUE);
	if (path[0] == '.' && path[1] == '/' && ft_strlen(path) == 2)
		return (no_such_file_or_folder(shell->trimmed_prompt, shell), FALSE);
	if (path[0] == '.' || path[0] == '/' || path)
	{
		if (path[0] == '.' && path[1] != '/')
			return (invalid_command(shell, path), FALSE);
		else if (path[0] == '.' && dot_at_path_start(shell, path) == TRUE)
			return (TRUE);
		else if (path[0] == '/' && slash_at_path_start(shell, path) == TRUE)
			return (TRUE);
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

int	dot_dot_slash_at_path_start(t_shell *shell, char *path)
{
	if (access(path, X_OK) == 0)
		return (TRUE);
	else
		return (no_such_file_or_folder(path, shell), FALSE);
}

int	dot_at_path_start(t_shell *shell, char *path)
{
	if (path[0] == '.' && access(path, X_OK) == 0)
		return (TRUE);
	return (no_such_file_or_folder(path, shell), FALSE);
}

int	slash_at_path_start(t_shell *shell, char *path)
{
	if (access(path, X_OK) == 0)
		return (TRUE);
	else
		return (no_such_file_or_folder(path, shell), FALSE);
}
