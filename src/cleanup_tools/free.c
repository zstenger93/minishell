/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:08:03 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 14:27:57 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_char_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_env(t_env *head)
{
	t_env	*next;

	while (head != NULL)
	{
		next = head->next;
		free(head->var_name);
		free(head->content);
		free(head);
		head = next;
	}
}

void	free_cmd_tbls(t_cmd_tbl *cmd_tbls)
{
	t_cmd_tbl	*curr;

	curr = cmd_tbls;
	while (curr != NULL)
	{
		free_tokens(curr->args);
		free_tokens(curr->redirs);
		free_char_array(curr->cmd_args);
		free(curr->cmd);
		curr = curr->next;
		free(cmd_tbls->heredoc_name);
		free(cmd_tbls);
		cmd_tbls = curr;
	}
}

void	free_at_exit(t_shell *shell)
{
	t_token	*token;

	// if (shell->print == FALSE)
	// 	printf("exit\n");
	if (shell->trimmed_prompt != NULL)
		free_cmd_tbls(shell->cmd_tbls);
	free_char_array(shell->cmd_paths);
	free(shell->terminal_prompt);
	free(shell->trimmed_prompt);
	free_char_array(shell->env);
	free_env(shell->env_head);
	free(shell->prev_prompt);
	free(shell->heredoc);
	free(shell->prompt);
	rl_clear_history();
}

void	free_at_child(t_shell *shell)
{
	t_token	*token;

	if (shell->trimmed_prompt != NULL)
		free_cmd_tbls(shell->cmd_tbls);
	free_char_array(shell->cmd_paths);
	free(shell->terminal_prompt);
	free_char_array(shell->env);
	free(shell->trimmed_prompt);
	free_env(shell->env_head);
	free(shell->prev_prompt);
	free(shell->heredoc);
	free(shell->prompt);
	rl_clear_history();
}
