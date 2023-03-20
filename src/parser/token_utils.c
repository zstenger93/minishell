/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:59:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/20 17:36:40 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_type	get_redirection_type(char *str, int start, int end)
{
	if (end - start == 2)
	{
		if (str[start] == '>')
			return (APPEND);
		return (HEREDOC);
	}
	else if (end - start == 1)
	{
		if (str[start] == '>')
			return (OUTPUT);
		return (INPUT);
	}
	return (UKNOWN);
}

bool	is_redirection(t_token *token)
{
	if (token == NULL)
		return (false);
	if (token->type == HEREDOC
		|| token->type == APPEND
		|| token->type == INPUT
		|| token->type == OUTPUT)
		return (true);
	return (false);
}

void	free_tokens(t_token *token)
{
	t_token	*next;

	while (token != NULL)
	{
		next = token->next;
		free(token->content);
		free(token);
		token = next;
	}
}
