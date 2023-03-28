/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:51:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/28 17:28:06 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_loop(t_shell *shell)
{
	while (TRUE)
	{
		terminal_prompt(shell);
		if (read_line(shell) == NULL)
			break ;
		update_env(shell);
		if (lexer(shell) == TRUE)
		{
			parser(shell);
			execute(shell, shell->cmd_tbls);
		}
		addhistory(shell);
	}
}

int	*read_line(t_shell *shell)
{
	shell->exec_on_pipe = FALSE;
	shell->should_execute = FALSE;
	if (isatty(fileno(stdin)))
		shell->prompt = readline(shell->terminal_prompt);
	else
	{
		char *line;
		line = get_next_line(fileno(stdin));
		shell->prompt = ft_strtrim(line, "\n");
		free(line);
	}
	shell->trimmed_prompt = ft_strtrim(shell->prompt, SPACES);
	if (shell->prompt == NULL)
		return (NULL);
	return ((void *)1);
}

void	update_env(t_shell *shell)
{
	if (shell->env != NULL)
		free_char_array(shell->env);
	shell->env = env_list_to_char(shell->env_head);
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
