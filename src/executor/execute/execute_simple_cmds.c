/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:43:25 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/22 20:03:57 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	exec_smpl_cmd(t_cmd_tbl *table, t_shell *shell)
{
	int		status;
	pid_t	pid;
	int		fd;

	pid = fork();
	if (pid == -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if (pid == 0)
	{
		if (has_wrong_redir(shell, table->redirs) == false)
		{
			fd = handle_redirections(shell);
			smpl_child_process(table, shell, fd);
		}
		else
			child_exit(shell);
	}
	waitpid(pid, &status, 0);
	if (has_wrong_redir(shell, table->redirs) == false)
		close_and_dup(shell);
	shell->exit_code = WEXITSTATUS(status);
	if (shell->cmd_has_been_executed == FALSE && shell->exit_code == 2)
		shell->exit_code = 258;
}

void	child_exit(t_shell *shell)
{
	free_at_child(shell);
	shell->exit_code = 258;
	exit(shell->exit_code);
}

void	smpl_child_process(t_cmd_tbl *table, t_shell *shell, int fd)
{
	char	*cmd_path;

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

void	close_and_dup(t_shell *shell)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	dup2(shell->std_fds[0], STDIN_FILENO);
	dup2(shell->std_fds[1], STDOUT_FILENO);
	if (shell->exit_code != 0)
		shell->cmd_has_been_executed = 0;
}
