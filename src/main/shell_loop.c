/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:51:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/07 18:17:49 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//shell->prev_prompt can be extracted from struct
void	shell_loop(t_shell *shell)
{
	while (TRUE)
	{
		terminal_prompt(shell);
		shell->prompt = readline(shell->terminal_prompt);
		shell->trimmed_prompt = ft_strtrim(shell->prompt, "\t ");
		builtins(shell);
		if (add_history_if(shell->prompt, shell->prev_prompt) == TRUE)
			shell->prev_prompt = shell->prompt;
		else
			free(shell->prompt);
		free(shell->trimmed_prompt);
	}
}

void	builtins(t_shell *shell)
{
	if (ft_strncmp(shell->trimmed_prompt, "export", 6) == 0)
		export(shell);
	else if (ft_strncmp(shell->trimmed_prompt, "env", 3) == 0)
		env(shell);
	else if (ft_strncmp(shell->trimmed_prompt, "pwd", 3) == 0)
		pwd(shell);
	else if (ft_strncmp(shell->trimmed_prompt, "exit", 4) == 0)
		exit_shell(shell);
	else if (ft_strncmp(shell->trimmed_prompt, "unset", 5) == 0)
		unset(shell);
}
