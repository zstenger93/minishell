/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:27:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 11:54:04 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool is_builtin(char *path)
{
	if (ft_strcmp(path, "export") == TRUE)
		return (TRUE);
	else if (ft_strcmp(path, "cd") == TRUE)
		return (TRUE);
	else if (ft_strcmp(path, "pwd") == TRUE)
		return (TRUE);
	else if (ft_strcmp(path, "env") == TRUE)
		return (TRUE);
	else if (ft_strcmp(path, "exit") == TRUE)
		return (TRUE);
	else if (ft_strcmp(path, "unset") == TRUE)
		return (TRUE);
	else if (ft_strcmp(path, "echo") == TRUE)
		return (TRUE);
	return (FALSE);
}


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
