/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:22:11 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/24 13:48:27 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	execute(t_shell *shell, t_cmd_tbl *cmd_table)
{
	// if (tables_have_wrong_redir(cmd_table, shell) == true) //exec heredocs only if we ahve wrong operators
	// 	shell->exit_code = 258;
	if (cmd_table != NULL && cmd_table->next == NULL) //exec without pipes
		exec_simple_cmd(cmd_table, shell);
	else if (cmd_table != NULL && cmd_table->next != NULL) //exec with pipes
		pipeline_loop(cmd_table, shell);
}

t_cmd_tbl	*get_last_cmd_tbl(t_cmd_tbl *table)
{
	while (table->next != NULL)
		table = table->next;
	return (table);
}

void	pipeline_loop(t_cmd_tbl *table, t_shell *shell)
{
	while (table->next != NULL)
	{
		execute_pipe(table, shell);
		table = table->next;
	}
	execute_last_pipe(table, shell);
}

void	execute_pipe(t_cmd_tbl *table, t_shell *shell)
{
	pid_t	pid;
	int		status;

	if (pipe(shell->pipe->fd) == -1)
		p_err("%s%s\n", SHELL, PIPE_ERROR);
	pid = fork();
	if (pid == -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if (pid == 0)
	{

		smpl_child_process(table, shell);
	}
	// waitpid(pid, &status, 0);
}

void	execute_last_pipe(t_cmd_tbl *table, t_shell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if (pid == 0)
	{
		dup2(shell->pipe->fd[1], STDOUT_FILENO);
		smpl_child_process(table, shell);
	}
	waitpid(pid, &status, 0);
	close_and_dup(shell);
}
