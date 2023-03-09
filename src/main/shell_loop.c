/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:51:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/09 18:39:23 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//
//
//
//FORKIN MAKE OUR FPRINTF TO PRINT ERRORS TO STDERR
//
//
//
void	shell_loop(t_shell *shell)
{
	while (TRUE)
	{
		terminal_prompt(shell);
		if (read_line(shell) == NULL)
			break ;
		builtins(shell);
		addhistory(shell);
	}
}

void	addhistory(t_shell *shell)
{
	if (add_history_if(shell->prompt, shell->prev_prompt) == TRUE)
		shell->prev_prompt = shell->prompt;
	else
		free(shell->prompt);
	free(shell->trimmed_prompt);
}

int	*read_line(t_shell *shell)
{
	shell->prompt = readline(shell->terminal_prompt);
	shell->trimmed_prompt = ft_strtrim(shell->prompt, "\t ");
	if (shell->prompt == NULL)
		return (NULL);
	return ((void *)1);
}

void	builtins(t_shell *shell)
{
	if (cmd(shell, "export", 6) == TRUE)
		export(shell);
	else if (cmd(shell, "cd", 2) == TRUE)
		cd(shell);
	else if (cmd(shell, "pwd", 3) == TRUE)
		pwd(shell);
	else if (cmd(shell, "env", 3) == TRUE)
		env(shell);
	else if (cmd(shell, "exit", 4) == TRUE)
		exit_shell(shell);
	else if (cmd(shell, "unset", 5) == TRUE)
		unset(shell);
	else if (cmd(shell, "clear", 5) == TRUE)
		clear_screen();
}
