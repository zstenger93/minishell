/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:57 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/13 08:33:29 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokenizer(t_shell *shell)
{
}

// void	print_token(t_token *tokens)
// {
// 	t_token	*curr;

// 	curr = tokens;
// 	while (curr->next != NULL)
// 	{
// 		printf("%s\n", curr->content);
// 		curr = curr->next;
// 	}
// }

// void	add_token(t_token **tokens, char *content)
// {
// 	t_token	*new;
// 	t_token	*curr;

// 	new = malloc(sizeof(t_token));
// 	new->content = content;
// 	new->next = NULL;
// 	if (*tokens == NULL)
// 	{
// 		*tokens = new;
// 		return ;
// 	}
// 	curr = *tokens;
// 	while (curr->next != NULL)
// 		curr = curr->next;
// 	curr->next = new;
// }
