/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:17:09 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/22 19:55:08 by zstenger         ###   ########.fr       */
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

bool	wrong_operator_check(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '|')
		return (syntax_error(str[0]), TRUE);
	if (has_wrong_pipe(str))
		p_err("%s%s\n", SHELL, PIPE_ERROR);
	while (str[++i])
	{
		if (is_operator(str[i - 1]) && is_space(str[i]))
		{
			i = skip_spaces(str, i);
			if (is_operator(str[i]))
			{
				if (str[i] == '<' && str[i + 1] == '<')
					return (FALSE);
				else
					return (syntax_error(str[i]), TRUE);
			}
		}
	}
	if (is_operator(str[ft_strlen(str) - 1]))
		return (syntax_error_newline(), TRUE);
	return (FALSE);
}
