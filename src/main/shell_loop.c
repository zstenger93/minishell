/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:51:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/06 15:47:27 by zstenger         ###   ########.fr       */
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
		builtins(shell);
		if (add_history_if(shell->prompt, shell->prev_prompt) == TRUE)
			shell->prev_prompt = shell->prompt;
		else
			free(shell->prompt);
	}
}

void	temp_exit(t_shell *shell)
{
	if (ft_strncmp(shell->prompt, "exit", 4) == 0
		&& ft_strlen(shell->prompt) == 4)
	{
		free(shell->terminal_prompt);
		free(shell->prev_prompt);
		free(shell->prompt);
		free_env(shell->env_head);
		free_char_array(shell->cmd_paths);
		exit(EXIT_SUCCESS);
	}
}

void	builtins(t_shell *shell)
{
	if (ft_strncmp(shell->prompt, "export", 6) == 0)
		export(shell);
	else if (ft_strncmp(shell->prompt, "env", 3) == 0)
		env(shell);
	else if (ft_strncmp(shell->prompt, "pwd", 3) == 0)
		pwd(shell);
	else if (ft_strncmp(shell->prompt, "exit", 4) == 0)
		exit_shell(shell);
}
