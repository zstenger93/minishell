/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:22:11 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/19 03:09:02 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(t_shell *shell, t_lexer *tokens)
{
	int	cmd_nb;

	if (cmd_nb == 1)
		exec_smple_cmd(shell, tokens);
	if (redirections in cmd)
		exec_smple_cmd_wth_redir(shell, tokens);
	else
		exec_on_pipeline(shell, tokens);
}

void	exec_smple_cmd(t_shell *shell, t_lexer *tokens)
{
	char	*cmd_path;

	if (path_check(command) == TRUE)
		execve(command, commands, shell->env_head);
	else
	{
		cmd_path = extract_path(shell, command);
		if (cmd_path == NULL)
		{
			free(cmd_path);
			return (NULL);
		}
		else if (access(cmd_path, X_OK) == TRUE)
			execve(cmd_path, commands, shell->env_head);
	}
}

void	exec_smple_cmd_wth_redir(t_shell *shell, t_lexer *tokens)
{
}

void	exec_on_pipeline(t_shell *shell, t_lexer *tokens)
{
	
}


void	execute_command(char *command, char **env)
{
	char	**commands;
	char	*cmd_path;
	char	*env_path;

	commands = ft_split(command, ' ');
	if (check_for_script(command) == TRUE)
		execve(command, commands, env);
	else if (path_check(commands[0]) == TRUE)
	{
		cmd_path = commands[0];
		execve(cmd_path, commands, env);
	}
	else
	{
		env_path = get_env(env);
		cmd_path = get_path(env_path, commands[0]);
		if (cmd_path == NULL)
		{
			free_array(commands);
			free(cmd_path);
		}
		else if (access(cmd_path, X_OK) == TRUE)
			execve(cmd_path, commands, env);
	}
}