/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:59:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/20 15:17:55 by jergashe         ###   ########.fr       */
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

t_token	*add_new_token2(t_token *tokens, t_token *new)
{
	t_token	*curr;

	if (tokens == NULL)
		return (new);
	curr = tokens;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	new->prev = curr;
	return (tokens);
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

t_token	*copy_token(t_token *token)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		printf("copy token malloc error\n");
	new->content = ft_strdup(token->content);
	new->type = token->type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
