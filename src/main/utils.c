/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:43:19 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/03 10:51:12 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_at_exit2(t_shell *shell);
int		minishell(int argc, char *argv, char **env);

int	main(int argc, char **argv, char **env)
{
	int	exit_status;

	if (argc >= 3 && !ft_strncmp(argv[1], "-c", 3))
	{
		exit_status = minishell(argc, argv[2], env);
		exit(exit_status);
	}
}

int	minishell(int argc, char *argv, char **env)
{	
	t_shell	shell;

	init_shell(&shell, env);
	shell.prompt = ft_strdup(argv);
	shell.trimmed_prompt = ft_strtrim(shell.prompt, SPACES);
	if (lexer(&shell) == TRUE && parser(&shell) == TRUE)
		execute(&shell, shell.cmd_tbls);
	free_at_exit2(&shell);
	return (shell.exit_code);
}

void	free_at_exit2(t_shell *shell)
{
	if (shell->trimmed_prompt != NULL)
		free_cmd_tbls(shell->cmd_tbls);
	free_char_array(shell->cmd_paths);
	free(shell->trimmed_prompt);
	free_char_array(shell->env);
	free_env(shell->env_head);
	free(shell->prev_prompt);
	free(shell->heredoc);
	free(shell->prompt);
	rl_clear_history();
}
