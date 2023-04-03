/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:17:09 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/03 09:33:15 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	bad_pipe(t_shell *shell)
{
	int	len;

	len = ft_strlen(shell->trimmed_prompt) - 1;
	if (shell->trimmed_prompt[0] == '|')
	{
		shell->exit_code = 2;
		return (syntax_error(shell->trimmed_prompt[0]), TRUE);
	}
	else if (shell->trimmed_prompt[len] == '|')
	{
		shell->exit_code = 2;
		return (syntax_error_newline(), TRUE);
	}
	return (FALSE);
}

int	lexer(t_shell *shell)
{
	if (is_empty_line_passed(shell) == TRUE || ft_strlen(shell->trimmed_prompt) == 0)
		return (FALSE);
	else if (bad_pipe(shell) == TRUE)
		return (FALSE);
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

// eg prompt -> ""
bool	is_empty_line_passed(t_shell *shll)
{
	if (shll->trimmed_prompt[0] == '~' && ft_strlen(shll->trimmed_prompt) == 1)
	{
		shll->exit_code = 126;
		return (p_err("%s: %s: %s\n", SHELL, "~", ISDIR), TRUE);
	}
	if ((shll->trimmed_prompt[0] == '>' && shll->trimmed_prompt[1] == '>'
		&& shll->trimmed_prompt[2] == '>') || (shll->trimmed_prompt[0] == '<'
		&& shll->trimmed_prompt[1] == '<' && shll->trimmed_prompt[2] == '<'))
	{
		shll->exit_code = 2;
		return (syntax_error(shll->trimmed_prompt[0]), TRUE);
	}
	if (shll->trimmed_prompt[0] == DQUOTE && shll->trimmed_prompt[1] == DQUOTE
		&& ft_strlen(shll->trimmed_prompt) == 2)
	{
		p_err("%s: %s\n", SHELL, CMD_NOT_FND);
		shll->cmd_has_been_executed = FALSE;
		shll->exit_code = 127;
		return (TRUE);
	}
	return (FALSE);
}

/*
checks if there is only space between operators and if so,
returns syntax error at the index of it's occourance
*/
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
