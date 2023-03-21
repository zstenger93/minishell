/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:17:09 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 12:34:57 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lexer(t_shell *shell)
{
	if (ft_strlen(shell->trimmed_prompt) == 0)
		return ;
	if (unclosed_quotes(shell->trimmed_prompt) == TRUE)
		shell->cmd_has_been_executed = FALSE;
	else if (expander(&shell->trimmed_prompt, shell) == FALSE)
		shell->cmd_has_been_executed = FALSE;
	if ((builtins(shell) == TRUE && cmd(shell, "echo", 4) == FALSE)
		|| is_builtin(shell) == FALSE)
	{
		if (wrong_operator_check(shell->trimmed_prompt) == TRUE)
			shell->cmd_has_been_executed = FALSE;
		if (special_char_check(shell->trimmed_prompt) == TRUE)
			shell->cmd_has_been_executed = FALSE;
		if (redir_check(shell->trimmed_prompt) == TRUE)
			shell->cmd_has_been_executed = FALSE;
	}
}
