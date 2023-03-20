/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:51:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/20 16:50:23 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_loop(t_shell *shell)
{
	t_cmd_tbl *table;
	t_token	*token;

	while (TRUE)
	{
		terminal_prompt(shell);
		if (read_line(shell) == NULL)
			break ;
		// expander(&shell->trimmed_prompt, shell);
		lexer(shell);
		parser(shell);
		// executor(shell);
		addhistory(shell);
	}
}

int	*read_line(t_shell *shell)
{
	shell->prompt = readline(shell->terminal_prompt);
	shell->trimmed_prompt = ft_strtrim(shell->prompt, "\t ");
	if (shell->prompt == NULL)
		return (NULL);
	return ((void *)1);
}

void	addhistory(t_shell *shell)
{
	t_token	*token;

	if (add_history_if(shell->prompt, shell->prev_prompt) == TRUE)
		shell->prev_prompt = shell->prompt;
	else
		free(shell->prompt);
	free(shell->trimmed_prompt);
}

bool	builtins(t_shell *shell)
{
	// if (cmd(shell, "<<", 2) == TRUE)
	// 	heredoc(shell, "stop");
	if (cmd(shell, "export", 6) == TRUE)
		return (export(shell), TRUE);
	else if (cmd(shell, "cd", 2) == TRUE)
		return (cd(shell), TRUE);
	else if (convert_to_lower(shell->trimmed_prompt, 3)
		&& cmd(shell, "pwd", 3) == TRUE)
		return (pwd(shell), TRUE);
	else if (convert_to_lower(shell->trimmed_prompt, 3)
		&& cmd(shell, "env", 3) == TRUE)
		return (env(shell), TRUE);
	else if (cmd(shell, "exit", 4) == TRUE)
		return (exit_shell(shell), TRUE);
	else if (cmd(shell, "unset", 5) == TRUE)
		return (unset(shell), TRUE);
	else if (convert_to_lower(shell->trimmed_prompt, 4)
		&& cmd(shell, "echo", 4) == TRUE)
		return (echo(shell), TRUE);
	return (FALSE);
}
