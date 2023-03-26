/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_without_pipes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:43:25 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/26 17:51:08 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	exec_without_pipes(t_cmd_tbl *table, t_shell *shell)
{
	int		status;
	pid_t	pid;

	pid = fork();
	shell->exec_on_pipe = FALSE;
	shell->should_execute = TRUE;
	if (pid == -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if (pid == 0)
	{
		if (has_wrong_redir(shell, table->redirs, table) == false)
		{
			shell->print = TRUE;
			handle_redirections(shell, table);
			execute_command(table, shell);
		}
		else
			child_exit(shell);
	}
	shell->print = FALSE;
	builtins(shell, table->cmd, table->cmd_args);
	waitpid(pid, &status, 0);
	if (has_wrong_redir(shell, table->redirs, table) == false)
		close_and_dup(shell);
	else
		shell->exit_code = 258;
}

void	child_exit(t_shell *shell)
{
	free_at_child(shell);
	exit(258);
}

void	close_and_dup(t_shell *shell)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	dup2(shell->std_fds[0], STDIN_FILENO);
	dup2(shell->std_fds[1], STDOUT_FILENO);
	if (shell->exit_code != 0)
		shell->cmd_has_been_executed = 0;
}
