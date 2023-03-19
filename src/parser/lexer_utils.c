/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:26:27 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/19 10:59:29 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	token_list_size(t_token *token)
{
	int		i;
	t_token	*curr;

	i = 0;
	curr = token;
	while (curr->next != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i + 1);
}

t_token	*get_new_token(char *str, t_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL) // something
		return (NULL);
	token->content = str;
	token->next = NULL;
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
	return (token);
}

void	print_tokens(t_token *token)
{
	t_token	*curr;
	
	curr = token;
	while (curr != NULL)
	{
		printf("%s: %d\n", curr->content, curr->type);
		curr = curr->next;
	}
}
