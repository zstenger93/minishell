/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:39:58 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/10 20:32:12 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//need to add $? option
void	expander(t_token *token, t_shell *shell)
{
	char	*expanded_token;
	char	*token_to_expand;
	t_token	*curr;

	curr = token;
	while (curr->next != NULL)
	{
		token_to_expand = var_to_expand(token);
		if (token_to_expand == NULL)
			return ;
		else
			expanded_token = expand(token_to_expand, shell);
		replace_var_with_content(token, token_to_expand, expanded_token);
		curr = curr->next;
	}
}

bool	is_dollar(char *token)
{
	if (token[0] == '$')
		return (TRUE);
	return (FALSE);
}

char	*var_to_expand(t_token *tokens)
{
	while (tokens->next != NULL)
	{
		if (is_dollar(tokens->content) == TRUE)
			return (tokens->content);
		tokens = tokens->next;
	}
	return (NULL);
}

char	*expand(char *token, t_shell *shell)
{
	int		i;
	char	*trimmed_token;
	char	*expanded_token;

	i = 0;
	trimmed_token = ft_strtrim(token, "$");
	if (trimmed_token[0] == '(')
	{
		while (trimmed_token[i] != '\0')
			i++;
		if (trimmed_token[i - 1] == ')')
			expanded_token = replace_variable(trimmed_token, shell);
		else
			expanded_token = ft_strdup("");
	}
	else
		expanded_token = replace_variable(trimmed_token, shell);
	return (expanded_token);
}

char	*replace_variable(char *variable, t_shell *shell)
{
	t_env	*curr;
	char	*space;
	char	*trimmed_variable;

	if (variable[0] == '(')
	{
		trimmed_variable = ft_strtrim(variable, "()");
		curr = find_env_var(shell->env_head, trimmed_variable);
		free(trimmed_variable);
		return (curr->content);
	}
	else if (variable[0] != '(' || variable[0] != ' ')
	{
		curr = find_env_var(shell->env_head, variable);
		return (curr->content);
	}
	space = ft_strdup("");
	return (space);
}

void	replace_var_with_content(t_token *token, char *token_to_expand, char *content)
{
	t_token	*curr;

	curr = token;
	while (curr->next != NULL)
	{
		if (curr->content == token_to_expand)
		{
			free(curr->content);
			curr->content = expand_variable(content);
		}
		curr = curr->next;
	}
}

char	*expand_variable(char *content)
{
	int		i;
	int		content_len;
	char	*var_content;

	i = -1;
	content_len = ft_strlen(content) + 1;
	var_content = malloc(sizeof(char) * content_len);
	while (content[++i] != '\0')
		var_content[i] = content[i];
	var_content[i] = '\0';
	return (var_content);
}
