/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:52:51 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/25 17:09:05 by zstenger         ###   ########.fr       */
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
	curr = token;
	while (curr != wrong)
	{
		if (curr->type == HEREDOC)
			heredoc(table, curr->next->content, shell);
		curr = curr->next->next;
	}
	return (true);
}
