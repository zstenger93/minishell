/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:27:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 12:47:07 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	path_check(char *cmd_path)
{
	if (cmd_path[0] == '.' || cmd_path[0] == '/')
	{
		if (cmd_path[0] == '.')
		{
			if (cmd_path[0] == '.' && access(cmd_path, X_OK) == 0)
				return (TRUE);
			return (no_such_file_or_folder(cmd_path), FALSE);
		}
		else if (cmd_path[0] == '/')
		{
			if (access(cmd_path, X_OK) == 0)
				return (TRUE);
			else
				return (no_such_file_or_folder(cmd_path), FALSE);
		}
	}
	return (FALSE);
}

//exit status?
int	no_such_file_or_folder(char *command)
{
	p_err("%s%s: %s\n", SHELL, command, strerror(ENOENT));
	return (FALSE);
}
