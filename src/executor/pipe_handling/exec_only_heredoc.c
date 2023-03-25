/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_only_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:11:27 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/25 17:15:43 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	tables_have_wrong_redir(t_cmd_tbl *table, t_shell *shell)
{
	bool		flag;
	t_cmd_tbl	*curr;

	flag = false;
	curr = table;
	while (curr != NULL && flag == false)
	{
		flag = has_heredoc_and_wrong_redir(curr->redirs);
		curr = curr->next;
	}
	if (flag == true && curr != NULL)
	{
		run_only_heredocs(table, curr, shell);
		return (true);
	}
	return (false);
}

bool	has_heredoc_and_wrong_redir(t_token *token)
{
	while (token != NULL)
	{
		if (is_good_redirection(token) == false)
			return (true);
		token = token->next->next;
	}
	return (false);
}

void	run_only_heredocs(t_cmd_tbl *start, t_cmd_tbl *last, t_shell *shll)
{
	t_token	*token;

	while (start != last->next)
	{
		token = start->redirs;
		while (token != NULL)
		{
			if (is_redirection(token) && is_redirection(token->next))
				break ;
			if (token->type == HEREDOC)
				heredoc(start, token->next->content, shll);
			token = token->next;
		}
		start = start->next;
	}
}
