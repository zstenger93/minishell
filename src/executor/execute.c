/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:22:11 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 13:03:38 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(t_shell *shell, t_cmd_tbl *cmd_table)
{
	char	**env;

	env = env_list_to_char(shell->env_head);
	if (cmd_table->next == NULL)
		exec_smpl_cmd(cmd_table, shell, env);
	// if (cmd_table->redirs != NULL)
	// 	exec_smple_cmd_wth_redir(shell, cmd_table);
	// else
	// 	exec_on_pipeline(shell, cmd_table);
}

void	exec_smpl_cmd(t_cmd_tbl *table, t_shell *shell, char **env)
{
	char	*env_path;
	char	*cmd_path;
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if ( pid == 0)
	{
		if (path_check(table->cmd) == TRUE)
			execve(table->cmd, table->cmd_args, env);
		else if (table->cmd[0] != '.' && table->cmd[0] != '/')
		{
			cmd_path = extract_path(shell, table->cmd);
			if (cmd_path == NULL)
			{
				free(cmd_path);
				shell->cmd_has_been_executed = 0;
				return ;
			}
			else if (access(cmd_path, X_OK) == 0)
				execve(cmd_path, table->cmd_args, env);
			free(cmd_path);
		}
	}
	waitpid(pid, &status, 0);
	shell->exit_code = WEXITSTATUS(status);
}

// void	exec_smple_cmd_wth_redir(t_cmd_tbl *table, t_shell *shell)
// {
// }

// void	exec_on_pipeline(t_cmd_tbl *table, t_shell *shell)
// {
// }
