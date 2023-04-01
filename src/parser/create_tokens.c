/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:16:07 by jergashe          #+#    #+#             */
/*   Updated: 2023/04/01 10:12:03 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* 
split_elements_to_tokens takes one pipe (str) and token
as input. Function takes token as argument to save space.
Function uses i and old_i as indexes to create a new token
from position old_i to i. And returns the head of token.
 */
t_token	*split_elements_to_tokens(char *str, t_token *token)
{
	int	i;
	int	old_i;

	i = 0;
	while (str[i] != '\0')
	{
		old_i = i;
		token = add_quote_token(str, &i, &old_i, token);
		token = add_word_token(str, &i, &old_i, token);
		token = add_redirection_token(str, &i, &old_i, token);
		token = add_flag_token(str, &i, &old_i, token);
		i = skip_spaces(str, i);
	}
	return (token);
}

t_token	*add_quote_token(char *str, int *i, int *old_i, t_token *token)
{
	char	quote;
	bool	stop;

	if (str[*i] == '\0')
		return (token);
	if (str[*i] != SQUOTE && str[*i] != DQUOTE)
		return (token);
	quote = str[(*i)++];
	stop = false;
	while (str[*i] != '\0' && stop == false)
	{
		if (str[*i] == quote && nb_esc_chars(str, *i) % 2 == 0)
			stop = true;
		(*i)++;
	}
	if (*i - 1 != *old_i)
		token = add_new_token(token, ft_strdup2(str, *old_i, *i), WORD);
	*old_i = *i;
	return (token);
}

t_token	*add_word_token(char *str, int *i, int *old_i, t_token *token)
{
	while ((ft_isalpha(str[*i]) || ft_isalnum(str[*i])
			|| is_printable(str[*i]))
		&& str[*i] != '\0')
		(*i)++;
	if (*i != *old_i)
	{
		token = add_new_token(token, ft_strdup2(str, *old_i, *i), WORD);
		*old_i = *i;
	}
	return (token);
}

t_token	*add_redirection_token(char *str, int *i, int *old_i, t_token *tk)
{
	char	redirection;
	t_type	red_type;

	if (str[*i] == '\0'
		|| ft_pf_strchr(REDIRECTIONS, str[*i]) == NULL)
		return (tk);
	redirection = str[*i];
	while (str[*i] == redirection
		&& str[*i] != '\0')
		(*i)++;
	red_type = get_redirection_type(str, *old_i, *i);
	tk = add_new_token(tk, ft_strdup2(str, *old_i, *i), red_type);
	*old_i = *i;
	return (tk);
}

t_token	*add_flag_token(char *str, int *i, int *old_i, t_token *token)
{
	if (str[*i] != '-')
		return (token);
	(*i)++;
	while (str[*i] != '\0' && str[*i] != ' ')
	{
		if (ft_isalpha(str[*i]) == 0
			&& str[*i] != '-'
			&& ft_isalnum(str[*i]))
			break ;
		(*i)++;
	}
	token = add_new_token(token, ft_strdup2(str, *old_i, *i), WORD);
	*old_i = *i;
	return (token);
}
