/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:52:51 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 18:35:20 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	has_wrong_redir(t_shell *shell, t_token *token, t_cmd_tbl *table)
{
	t_token	*wrong;
	t_token	*curr;

	wrong = token;
	while (wrong != NULL)
	{
		if (is_redirection(wrong) == false)
		{
			wrong = wrong->next;
			continue ;
		}
		if (is_good_redirection(wrong) == false)
			break ;
		wrong = wrong->next->next;
	}
	if (wrong == NULL)
		return (false);
	execute_only_heredocs(shell, table, wrong);
	return (true);
}

void	execute_only_heredocs(t_shell *shll, t_cmd_tbl *tabl, t_token *end)
{
	t_token	*start;
	char	*tmp;

	start = tabl->redirs;
	while (start != end && start != NULL)
	{
		if (start->type == HEREDOC)
		{
			tmp = stop_word(start->next->content, shll);
			free(start->next->content);
			start->next->content = tmp;
			heredoc(tabl, start->next->content, shll);
		}
		start = start->next;
	}
}
