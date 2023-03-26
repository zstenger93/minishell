/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:51:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/26 11:22:30 by jergashe         ###   ########.fr       */
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
		lexer(shell);
		parser(shell);
		execute(shell, shell->cmd_tbls);
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

bool	builtins(t_shell *shell, char *cmd, char **args)
{
	if (ft_strncmp(cmd, "export", 6) == 0)
		return (export(shell), TRUE);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		return (cd(shell), TRUE);
	else if (convert_to_lower(shell->trimmed_prompt, 3)
		&& ft_strncmp(cmd, "pwd", 3) == 0)
		return (pwd(shell, args), TRUE);
	else if (convert_to_lower(cmd, 3)
		&& ft_strncmp(cmd, "env", 3) == 0)
		return (env(shell, args), TRUE);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		return (TRUE);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		return (unset(shell), TRUE);
	else if (convert_to_lower(shell->trimmed_prompt, 4)
		&& ft_strncmp(cmd, "echo", 4) == 0)
	{
		echo(shell);
		if (shell->exit_code != 127)
			shell->exit_code = 0;
		return (TRUE);
	}
	return (FALSE);
}
