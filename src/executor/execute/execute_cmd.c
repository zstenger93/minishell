/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:34:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/26 10:52:23 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	execute_command(t_cmd_tbl *table, t_shell *shell)
{
	char	*cmd_path;

	if (builtins(shell, table->cmd, table->cmd_args) == TRUE)
		exit(shell->exit_code);
	else if (path_check(table->cmd, shell) == TRUE)
	{
		shell->cmd_has_been_executed = 1;
		execve(table->cmd, table->cmd_args, shell->env);
	}
	else if (table->cmd[0] != '.' && table->cmd[0] != '/')
	{
		cmd_path = extract_path(shell, table->cmd);
		if (cmd_path == NULL)
			clear_and_exit(shell, cmd_path);
		else if (access(cmd_path, X_OK) == 0)
		{
			shell->cmd_has_been_executed = 1;
			execve(cmd_path, table->cmd_args, shell->env);
		}
	}
}

void	clear_and_exit(t_shell *shell, char *cmd_path)
{
	free(cmd_path);
	free_at_child(shell);
	shell->exit_code = 127;
	shell->cmd_has_been_executed = 0;
	exit(shell->exit_code);
}
