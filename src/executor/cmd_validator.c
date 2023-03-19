/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:34:21 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/19 06:07:26 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cmd_validator(char *command, t_shell *shell)
{
	char	*cmd_path;

	if (path_with_bin_check(command) == TRUE)
	{
		if (path_check(command) == TRUE)
			return (TRUE);
		else
		{
			cmd_path = extract_path(shell, command);
			if (cmd_path == NULL)
			{
				free(cmd_path);
				return (FALSE);
			}
			else if (access(cmd_path, X_OK) == TRUE)
				return (TRUE);
			free(cmd_path);
		}
		return (TRUE);
	}
	return (FALSE);
}

char	*extract_path(t_shell *shell, char *command)
{
	int		i;
	char	*path;
	char	*slash_cmd;

	i = 0;
	while (shell->cmd_paths[i] != NULL)
	{
		slash_cmd = ft_nm_strjoin("/", command);
		path = ft_nm_strjoin(shell->cmd_paths[i], slash_cmd);
		free(slash_cmd);
		if (path == NULL)
		{
			free(path);
			return (invalid_command(shell, command), NULL);
		}
		else if (access(path, X_OK) == TRUE)
			return (path);
		i++;
		free(path);
	}
	invalid_command(shell, command);
	return (NULL);
}

void	invalid_command(t_shell *shell, char *command)
{
	shell->exit_code = 127;
	p_err("%s%s%s\n", SHELL, command, INVALID_CMD);
}
