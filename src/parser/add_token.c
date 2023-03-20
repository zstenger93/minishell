/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:16:07 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/20 15:17:04 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool is_printable(char c) {
	int	ascii;

	ascii = (int)c;

	if ((ascii >= 33 && ascii <= 47)
		|| (ascii >= 58 && ascii <= 59)
		|| (ascii >= 63 && ascii <= 64)
		|| ascii == 61
		|| (ascii >= 91 && ascii <= 94)
		|| (ascii >= 123 && ascii <= 126)
		|| ascii == 96)
		return true;
	return false;
}

t_token *add_quote_token(char *str, int *i, int *old_i, t_token *token)
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
	token = add_new_token(token, ft_strdup2(str, *old_i, *i), WORD);
	*old_i = *i;
	return (token);
}

t_token *add_word_token(char *str, int *i, int *old_i, t_token *token)
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

t_token *add_redirection_token(char *str, int *i, int *old_i, t_token *token) // add paranthases
{
	char	redirection;
	t_type	red_type;

	if (str[*i] == '\0'
		|| ft_pf_strchr(REDIRECTIONS, str[*i]) == NULL)
		return (token);
	redirection = str[*i];
	while (str[*i] == redirection
		&& str[*i] != '\0')
		(*i)++;
	red_type = get_redirection_type(str, *old_i, *i);
	token = add_new_token(token, ft_strdup2(str, *old_i, *i), red_type);
	*old_i = *i;
	return (token);
}

t_token *add_flag_token(char *str, int *i, int *old_i, t_token *token)
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

