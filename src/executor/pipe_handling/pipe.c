/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:54:56 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/28 09:11:30 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	exec_pipes(t_cmd_tbl *table, t_shell *shell)
{
	int	status;
	int	pid;

	while (table->next != NULL)
	{
		pipe_child_process(table, shell);
		table = table->next;
	}
	exec_last_pipe(table, shell);
	pid = waitpid(0, &status, 0);
	while (pid != -1)
		pid = waitpid(0, &status, 0);
	shell->exit_code = status;
}

void	pipe_child_process(t_cmd_tbl *table, t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	if (pipe(fd) == -1)
		p_err("%s%s\n", SHELL, PIPE_ERROR);
	pid = fork();
	if (pid <= -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if (pid == 0)
	{
		shell->print = TRUE;
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		handle_redirections(shell, table);
		execute_command(table, shell);
	}
	shell->print = FALSE;
	waitpid_to_get_exit_status(pid, shell, &status);
	builtins(shell, table->cmd, table->cmd_args);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void	exec_last_pipe(t_cmd_tbl *table, t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	pid = fork();
	shell->should_execute = TRUE;
	if (pid == -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if (pid == 0)
	{
		shell->print = TRUE;
		if (pipe_has_redirs(table->redirs) == false)
			dup2(shell->std_fds[1], STDOUT_FILENO);
		handle_redirections(shell, table);
		execute_command(table, shell);
	}
	dup2(shell->std_fds[0], STDIN_FILENO);
	dup2(shell->std_fds[1], STDOUT_FILENO);
	shell->print = FALSE;
	builtins(shell, table->cmd, table->cmd_args);
}

bool	pipe_has_redirs(t_token *token)
{
	while (token != NULL)
	{
		if (token->type == APPEND
			|| token->type == OUTPUT)
			return (true);
		token = token->next;
	}
	return (false);
}
