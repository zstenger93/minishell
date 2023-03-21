/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:12:52 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 18:29:22 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_redirections(t_shell *shell)
{
	t_token	*curr;

	curr = shell->cmd_tbls->redirs;
	while (curr != NULL)
	{
		if (curr->type == HEREDOC && curr->next->type == WORD)
			heredoc(shell, curr->next->content);
		else if (curr->type == OUTPUT && curr->next->type == WORD)
			open_file(OUTPUT, curr->next->content, shell);
		else if (curr->type == APPEND && curr->next->type == WORD)
			open_file(APPEND, curr->next->content, shell);
		else if (curr->type == INPUT && curr->next->type == WORD)
			open_file(INPUT, curr->next->content, shell);
		curr = curr->next->next;
	}
	return (0);
}

void	input_redirection(t_type type, char *file_name, t_shell *shell)
{		
}

// if (is_redirection(curr) && curr->next != NULL && is_redirection(curr->next))
// if (curr->type == HEREDOC && curr->next->type == WORD)
// {
// 	// handle heredoc(curr) curr->next has a stop word
// 	curr = curr->next->next;
// }
// else if (curr->next != NULL && curr->next->type == WORD)
// {
// 	// open_file(curr->type, curr->next->content);
// 	curr = curr->next->next;
// }
