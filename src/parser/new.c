/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:29:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/19 11:07:13 by jergashe         ###   ########.fr       */
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
	token = add_new_token(token, ft_strdup2(str, *old_i, *i), ARG);
	*old_i = *i;
	return (token);
}

t_token *add_word_token(char *str, int *i, int *old_i, t_token *token)
{
	if (ft_isalpha(str[*i]) == 0)
		return (token);
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
	token = add_new_token(token, ft_strdup2(str, *old_i, *i), ARG);
	*old_i = *i;
	return (token);
}

t_token	*split_elements(char *str, t_token *token) // check if index returned by functions is correct
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
	print_tokens(token);
	return (token);
}

void	tokenize(char **str_arr)
{
	int	i;
	t_token	*token;

	i = 0;
	token = NULL;
	while (str_arr[i] != NULL)
	{
		token = split_elements(str_arr[i++], token);
		printf("\n");
	}
}









// int	skip_quotes_2(char *str, int index)
// {
// 	char	quote;

// 	if (str[index] == '\0')
// 		return (index);
// 	if (str[index] != SQUOTE && str[index] != DQUOTE)
// 		return (index);
// 	quote = str[index++];
// 	while (str[index] != '\0')
// 	{
// 		if (str[index] != quote && nb_esc_chars(str, index) % 2 == 1)
// 		{
// 			return (index + 1);
// 		}
// 		index++;
// 	}
// 	return (index);
// }

// int	skip_word(char *str, int index)
// {
// 	while ((ft_isalpha(str[index]) || ft_isalnum(str[index]))
// 		&& str[index] != '\0')
// 		index++;
// 	return (index);
// }

// int	skip_redirections(char *str, int index)
// {
// 	char	redirection;

// 	if (str[index] == '\0'
// 		|| ft_pf_strchr(REDIRECTIONS, str[index]) == NULL)
// 		return (index);
// 	redirection = str[index];
// 	while (str[index] == redirection
// 		&& str[index] != '\0')
// 		index++;
// 	return (index);
// }


// t_token	*split_elements(char *str, t_token *token) // check if index returned by functions is correct
// {
// 	int	i;
// 	int	old_i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		old_i = i;
// 		add_quote_token(str, &i, &old_i, token);
// 		if (old_i != i)
// 		{
// 			token = add_new_token(token, ft_strdup2(str, old_i, i));
// 			old_i = i;
// 		}
// 		i = add_word_token(str, i);
// 		if (old_i != i)
// 		{
// 			token = add_new_token(token, ft_strdup2(str, old_i, i));
// 			old_i = i;
// 		}	
// 		i = add_redirection_token(str, i);
// 		if (old_i != i)
// 			token = add_new_token(token, ft_strdup2(str, old_i, i));
// 		i = skip_spaces(str, i);
// 	}
// 	return (token);
// }

// void	tokenize(char **str_arr)
// {
// 	int	i;
// 	t_token	*token;

// 	i = 0;
// 	token = NULL;
// 	while (str_arr[i] != NULL)
// 	{
// 		split_elements(str_arr[i++], token);
// 		printf("\n");
// 	}
	
// }

// awk F',' '{ total = 0; for (i = 2; i <= NF; i++) { total += $i }; avg = total / (NF - 1); if (avg > 90) { print $1 } }' OUTFILE.txt