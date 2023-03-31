/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:17:09 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 09:55:14 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer(t_shell *shell)
{
	if (ft_strlen(shell->trimmed_prompt) == 0)
		return (FALSE);
	if (shell->trimmed_prompt[0] == DQUOTE
		&& shell->trimmed_prompt[1] == DQUOTE
		&& ft_strlen(shell->trimmed_prompt) == 2)
	{
		p_err("%s: %s\n", SHELL, CMD_NOT_FND);
		shell->cmd_has_been_executed = FALSE;
		shell->exit_code = 127;
		return (FALSE);
	}
	else if (shell->trimmed_prompt[0] == '|')
	{
		shell->exit_code = 2;
		return (syntax_error(shell->trimmed_prompt[0]), FALSE);
	}
	else if (unclosed_quotes(shell->trimmed_prompt) == TRUE)
	{
		shell->cmd_has_been_executed = FALSE;
		return (FALSE);
	}
	else if (wrong_operator_check(shell->trimmed_prompt) == TRUE)
	{
		shell->exit_code = 2;
		shell->cmd_has_been_executed = FALSE;
	}
	return (TRUE);
}

bool	wrong_operator_check(char *str)
{
	int	i;

	i = 0;
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
