/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:57 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/10 20:22:59 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup2(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
	{
		printf("FT_STRDUP2\n");
		return (NULL);
	}
	i = -1;
	while (start + ++i != end)
		result[i] = str[i + start];
	result[i] = '\0';
	return (result);
}

void	print_token(t_token *tokens)
{
	t_token	*curr;

	curr = tokens;
	while (curr->next != NULL)
	{
		printf("%s\n", curr->content);
		curr = curr->next;
	}
}

void	add_token(t_token **tokens, char *content)
{
	t_token	*new;
	t_token	*curr;

	new = malloc(sizeof(t_token));
	new->content = content;
	new->next = NULL;
	if (*tokens == NULL)
	{
		*tokens = new;
		return ;
	}
	curr = *tokens;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

// in loop first token second statement just word
void	identify_tokens(t_shell *shell)
{
	int		i;
	int		start_token;
	bool	is_token;
	bool	is_dollar;

	i = -1;
	is_token = FALSE;
	is_dollar = FALSE;
	if (ft_pf_strchr(TOKENS, shell->trimmed_prompt[0]) != NULL)
		is_token = TRUE;
	start_token = 0;
	while (shell->trimmed_prompt[++i] != '\0')
	{
		if (ft_pf_strchr("$", shell->trimmed_prompt[i]) != NULL && shell->trimmed_prompt[i] != ')' && is_token == FALSE)
		{
			add_token(shell->tokens, ft_strdup2(shell->trimmed_prompt, start_token, i));
			start_token = i;
			is_token = TRUE;
		}
		if (ft_pf_strchr(TOKENS, shell->trimmed_prompt[i]) != NULL
			&& is_token == TRUE)
		{
			add_token(shell->tokens, ft_strdup2(shell->trimmed_prompt, start_token, i));
			start_token = i;
			is_token = FALSE;
		}
		else if (is_token == FALSE && ft_pf_strchr(TOKENS, shell->trimmed_prompt[i]) == NULL)
		{
			add_token(shell->tokens, ft_strdup2(shell->trimmed_prompt, start_token, i));
			is_token = TRUE;
			start_token = i;
		}
	}
	add_token(shell->tokens, ft_strdup2(shell->trimmed_prompt, start_token, i));
}
// 	printf("Unexpected error near token '%c'", prompt[--i]);
