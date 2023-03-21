/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:22:11 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 17:34:45 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(t_shell *shell, t_cmd_tbl *cmd_table)
{
	if (cmd_table != NULL)
		if (cmd_table->next == NULL)
			exec_smpl_cmd(cmd_table, shell);
}
	// if (cmd_table->redirs != NULL)
	// 	exec_smple_cmd_wth_redir(shell, cmd_table);
	// else
	// 	exec_on_pipeline(shell, cmd_table);

void	exec_smpl_cmd(t_cmd_tbl *table, t_shell *shell)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if (pid == 0)
		smpl_child_process(table, shell);
	waitpid(pid, &status, 0);
	shell->exit_code = WEXITSTATUS(status);
	if (shell->exit_code != 0)
		shell->cmd_has_been_executed = 0;
}

void	smpl_child_process(t_cmd_tbl *table, t_shell *shell)
{
	char	*cmd_path;

	handle_redirections(shell);
	if (path_check(table->cmd, shell) == TRUE)
	{
		shell->cmd_has_been_executed = 1;
		execve(table->cmd, table->cmd_args, shell->env);
	}
	else if (table->cmd[0] != '.' && table->cmd[0] != '/')
	{
		cmd_path = extract_path(shell, table->cmd);
		if (cmd_path == NULL)
		{
			free(cmd_path);
			free_at_child(shell);
			shell->exit_code = 127;
			shell->cmd_has_been_executed = 0;
			exit(shell->exit_code);
		}
		else if (access(cmd_path, X_OK) == 0)
		{
			shell->cmd_has_been_executed = 1;
			execve(cmd_path, table->cmd_args, shell->env);
		}
	}
}

// void	exec_smple_cmd_wth_redir(t_cmd_tbl *table, t_shell *shell)
// {
// }

// void	exec_on_pipeline(t_cmd_tbl *table, t_shell *shell)
// {
// }
