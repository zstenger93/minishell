/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:26:27 by jergashe          #+#    #+#             */
/*   Updated: 2023/04/01 09:48:23 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

*/
t_token	*get_new_token(char *str, t_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		p_err("%s%s\n", SHELL, MALLOC_FAIL);
	token->content = str;
	token->next = NULL;
	token->prev = NULL;
	token->type = type;
	return (token);
}

t_token	*add_new_token(t_token *token, char *str, t_type type)
{
	t_token	*curr;
	t_token	*new;

	if (token == NULL)
		return (get_new_token(str, type));
	curr = token;
	while (curr->next != NULL)
		curr = curr->next;
	new = get_new_token(str, type);
	curr->next = new;
	new->prev = curr;
	return (token);
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

t_token	*copy_token(t_token *token)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		p_err("%s%s\n", SHELL, MALLOC_FAIL);
	new->content = ft_strdup(token->content);
	new->type = token->type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
