/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:34:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/27 14:24:56 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	execute_command(t_cmd_tbl *table, t_shell *shell)
{
	char	*cmd_path;
	int		exit_code;

	if (builtins(shell, table->cmd, table->cmd_args) == TRUE)
	{
		exit_code = shell->exit_code;
		free_at_child(shell);
		exit(exit_code);
	}
	else if (path_check(table->cmd, shell) == TRUE)
		final_exec(cmd_path, table, shell);
	else if (table->cmd[0] != '.' && table->cmd[0] != '/')
	{
		cmd_path = extract_path(shell, table->cmd);
		if (cmd_path == NULL)
			clear_and_exit(shell, cmd_path);
		else if (access(cmd_path, X_OK) == 0)
			final_exec(cmd_path, table, shell);
	}
}

void	final_exec(char *cmd_path, t_cmd_tbl *table, t_shell *shell)
{
	char	**cmd_args;
	char	**env;
	int		exit_code;

	exit_code = shell->exit_code;
	shell->cmd_has_been_executed = 1;
	cmd_args = copy_2d_char_array(table->cmd_args);
	env = copy_2d_char_array(shell->env);
	free_at_child(shell);
	if (execve(cmd_path, cmd_args, env) == -1)
	{
		p_err("%s%s\n", SHELL, strerror(errno));
		free(cmd_path);
		free_char_array(cmd_args);
		free_char_array(env);
		exit(exit_code);
	}
}

char	**copy_2d_char_array(char **array)
{
	int		i;
	char	**result;

	i = 0;
	while (array[i] != NULL)
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (result == NULL)
		p_err("%s%s\n", SHELL, MALLOC_FAIL);
	i = -1;
	while (array[++i] != NULL)
		result[i] = ft_strdup(array[i]);
	result[i] = NULL;
	return (result);
}

void	clear_and_exit(t_shell *shell, char *cmd_path)
{
	free(cmd_path);
	free_at_child(shell);
	shell->exit_code = 127;
	shell->cmd_has_been_executed = 0;
	exit(shell->exit_code);
}
