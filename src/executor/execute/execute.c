/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:22:11 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/23 17:36:39 by zstenger         ###   ########.fr       */
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
		exec_on_pipeline(cmd_table, shell);
}

void	exec_on_pipeline(t_cmd_tbl *table, t_shell *shell)
{
	int	status;
	int	pid;

	while (table != NULL && table->next != NULL && table->next->next != NULL
		&& has_wrong_redir(shell, table->redirs) == false)
	{
		child_process_on_pipeline(table, shell);
		table = table->next;
	}
	exec_last_pipe(table->next, shell);
	pid = waitpid(0, &status, 0);
	while (pid != -1)
		pid = waitpid(0, &status, 0);
	shell->exit_code = status;
	// if (has_wrong_redir(shell, table->redirs) == true) //not sure if this is good idea here
	// 	close_and_dup(shell);
}

void	redirect_and_execute(t_cmd_tbl *table, t_shell *shell, int fd[2])
{
	if (has_wrong_redir(shell, table->redirs) == false)
	{
		handle_redirections(shell);
		smpl_child_process(table, shell);
	}
	else
		child_exit(shell);
}

void	child_process_on_pipeline(t_cmd_tbl *table, t_shell *shell)
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
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		redirect_and_execute(table, shell, fd);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, &status, 0);
	close_and_dup(shell);
}

void	exec_last_pipe(t_cmd_tbl *table, t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	pid = fork();
	if (pid == -1)
		p_err("%s%s\n", SHELL, FORK_ERROR);
	else if (pid == 0)
	{
		handle_redirections(shell);
		smpl_child_process(table, shell);
	}
}

// void	ft_wait(void)
// {
// 	int	exit_status;
// 	int	process_id;
// 	int	status;
// 	int	signal_number;

// 	process_id = waitpid(0, &status, 0);
// 	dprintf(2 ,
// 		"\t\tPROCESS WITH ID %d EXITED\n", process_id);
// 	while (process_id != -1)
// 	{
// 		if (WIFEXITED(status))
// 		{
// 			exit_status = WEXITSTATUS(status);
// 			if (exit_status != 0 && exit_status > 106)
// 				dprintf(2, "My error: %s with exit status %d\n",
// 				strerror(exit_status), exit_status);
// 			else
// 				printf("Child process with pid: %d terminated with zero exit status %d\n",
// 				process_id, exit_status);
// 		}
// 		else if (WIFSIGNALED(status))
// 		{
// 			signal_number = WTERMSIG(status);
// 			printf("Child process with pid: %d terminated by signal %d\n",
// 			process_id, signal_number);
// 		}
// 		process_id = waitpid(0, &status, 0);
// 		dprintf(2 ,"\t\tPROCESS WITH ID %d EXITED\n", process_id);
// 	}
// }