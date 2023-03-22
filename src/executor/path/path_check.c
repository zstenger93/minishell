/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:27:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/22 19:29:00 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	path_check(char *cmd_path, t_shell *shell)
{
	if (cmd_path[0] == '.' || cmd_path[0] == '/')
	{
		if (cmd_path[0] == '.')
		{
			if (cmd_path[0] == '.' && access(cmd_path, X_OK) == 0)
				return (TRUE);
			return (no_such_file_or_folder(cmd_path, shell), FALSE);
		}
		else if (cmd_path[0] == '/')
		{
			if (access(cmd_path, X_OK) == 0)
				return (TRUE);
			else
				return (no_such_file_or_folder(cmd_path, shell), FALSE);
		}
	}
	return (FALSE);
}

int	no_such_file_or_folder(char *command, t_shell *shell)
{
	p_err("%s%s: %s\n", SHELL, command, strerror(ENOENT));
	shell->exit_code = 1;
	return (FALSE);
}
