/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:54:56 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/03 12:12:09 by zstenger         ###   ########.fr       */
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
}

void	pipe_child_process(t_cmd_tbl *table, t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		if (shell->print == TRUE)
			p_err("%s%s\n", SHELL, PIPE_ERROR);
	}
	pid = fork();
	shell->should_execute = TRUE;
	if (pid <= -1)
	{
		if (shell->print == TRUE)
			p_err("%s%s\n", SHELL, FORK_ERROR);
	}
	else if (pid == 0)
		pipe_exec_in_child(table, shell, fd[0], fd[1]);
	shell->print = FALSE;
	if (table->cmd != NULL)
		builtins(shell, table->cmd, table->cmd_args);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void	pipe_exec_in_child(t_cmd_tbl *t, t_shell *s, int fd_in, int fd_out)
{
	signals_child(&s->mirror_termios);
	s->print = TRUE;
	close(fd_in);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	handle_redirections(s, t);
	execute_command(t, s);
}

void	exec_last_pipe(t_cmd_tbl *table, t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	pid = fork();
	shell->should_execute = TRUE;
	if (pid == -1)
	{
		if (shell->print == TRUE)
			p_err("%s%s\n", SHELL, FORK_ERROR);
	}
	else if (pid == 0)
	{
		signals_child(&shell->mirror_termios);
		shell->print = TRUE;
		if (pipe_has_redirs(table->redirs) == false)
			dup2(shell->std_fds[1], STDOUT_FILENO);
		handle_redirections(shell, table);
		execute_command(table, shell);
	}
	waitpid_to_get_exit_status(pid, shell, &status);
	if (table->cmd != NULL)
		builtins(shell, table->cmd, table->cmd_args);
	if (has_wrong_redir(shell, table->redirs, table) == false)
		close_and_dup(shell);
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
