/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:34:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/29 15:23:45 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	execute_command(t_cmd_tbl *table, t_shell *shell)
{
	char	*cmd_path;
	int		exit_code;

	if (table->cmd == NULL)
		child_exit(shell);
	if (builtins(shell, table->cmd, table->cmd_args) == TRUE)
	{
		exit_code = shell->exit_code;
		free_at_child(shell);
		exit(exit_code);
	}
	else if (path_check(table->cmd, shell) == TRUE)
		final_exec(table->cmd, table, shell);
	else if (table->cmd[0] != '.' && table->cmd[0] != '/')
	{
		cmd_path = extract_path(shell, table->cmd);
		if (cmd_path == NULL)
			clear_and_exit(shell, cmd_path, table);
		else if (access(cmd_path, X_OK) == 0)
			final_exec(cmd_path, table, shell);
	}
}

void	final_exec(char *cmd_path, t_cmd_tbl *table, t_shell *shell)
{
	char	**cmd_args;
	char	**env;
	int		exit_code;

	if (is_a_directory(shell, table->cmd) == TRUE)
		child_exit(shell);
	exit_code = shell->exit_code;
	shell->cmd_has_been_executed = 1;
	cmd_args = copy_2d_char_array(table->cmd_args);
	env = copy_2d_char_array(shell->env);
	// free_at_child(shell);
	if (execve(cmd_path, cmd_args, env) == -1)
	{
		p_err("%s%s\n", SHELL, strerror(errno));
		free(cmd_path);
		free_char_array(cmd_args);
		free_char_array(env);
		exit(exit_code);
	}
}

bool	is_a_directory(t_shell *shell, char *cmd)
{
	int	i;
	int	len;
	i = 0;
	len = ft_strlen(cmd);

	if (cmd[0] == '/' && cmd[len - 1] == '/')
	{
		p_err("%s%s: %s\n", SHELL, cmd, ISDIR);
		shell->exit_code = 126;
		return (TRUE);
	}
	return (FALSE);
}