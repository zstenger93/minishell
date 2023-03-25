/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_without_pipes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:43:25 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/25 20:07:27 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	exec_without_pipes(t_cmd_tbl *table, t_shell *shell)
{
	int		status;
	pid_t	pid;

	if (ft_strcmp(table->cmd, "exit") == TRUE)
	{
		exit_shell(shell, table->cmd, table->cmd_args);
		return ;
	}
	pid = fork();
	if (pid == -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if (pid == 0)
	{
		if (has_wrong_redir(shell, table->redirs, table) == false)
		{
			handle_redirections(shell, table);
			execute_command(table, shell);
		}
		else
			child_exit(shell);
	}
	waitpid(pid, &status, 0);
	if (has_wrong_redir(shell, table->redirs, table) == false)
		close_and_dup(shell);
	else
		shell->exit_code = 258;
}

void	child_exit(t_shell *shell)
{
	free_at_child(shell);
	shell->exit_code = 258;
	exit(shell->exit_code);
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
