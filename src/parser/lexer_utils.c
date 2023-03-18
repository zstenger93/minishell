/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:26:27 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/17 08:27:24 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer_list_size(t_lexer *lexer)
{
	int		i;
	t_lexer	*curr;

	i = 0;
	curr = lexer;
	while (curr->next != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i + 1);
}

t_lexer	*first_lexer(char *str)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	if (lexer == NULL)
		printf("NULL");
	lexer->token = str;
	lexer->next = NULL;
	return (lexer);
}

t_lexer	*add_new_lexer(t_lexer *lexer, char *str)
{
	t_lexer	*curr;
	t_lexer	*new;

	if (lexer == NULL)
	{
		lexer = malloc(sizeof(t_lexer));
		lexer->next = NULL;
		lexer->token = str;
		return (lexer);
	}
	curr = lexer;
	while (curr->next != NULL)
		curr = curr->next;
	new = malloc(sizeof(t_lexer));
	new->next = NULL;
	new->token = str;
	curr->next = new;
	return (lexer);
}

void	print_lexer(t_lexer *lexer)
{
	t_lexer	*curr;
	
	curr = lexer;
	while (curr != NULL)
	{
		printf("%s\n", curr->token);
		curr = curr->next;
	}
}
