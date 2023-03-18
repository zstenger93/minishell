/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:29:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/18 09:01:01 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_lexer *add_quote_token(char *str, int *i, int *old_i, t_lexer *lexer)
{
	char	quote;
	bool	stop;

	if (str[*i] == '\0')
		return (lexer);
	if (str[*i] != SQUOTE && str[*i] != DQUOTE)
		return (lexer);
	quote = str[(*i)++];
	stop = false;
	while (str[*i] != '\0' && stop == false)
	{
		if (str[*i] == quote && nb_esc_chars(str, *i) % 2 == 0)
			stop = true;
		(*i)++;
	}
	lexer = add_new_lexer(lexer, ft_strdup2(str, *old_i, *i));
	*old_i = *i;
	return (lexer);
}

t_lexer *add_word_token(char *str, int *i, int *old_i, t_lexer *lexer)
{
	while ((ft_isalpha(str[*i]) || ft_isalnum(str[*i]))
		&& str[*i] != '\0')
		(*i)++;
	if (*i != *old_i)
	{
		lexer = add_new_lexer(lexer, ft_strdup2(str, *old_i, *i));
		*old_i = *i;
	}
	return (lexer);
}

t_lexer *add_redirection_token(char *str, int *i, int *old_i, t_lexer *lexer) // add paranthases
{
	char	redirection;

	if (str[*i] == '\0'
		|| ft_pf_strchr(REDIRECTIONS, str[*i]) == NULL)
		return (lexer);
	redirection = str[*i];
	while (str[*i] == redirection
		&& str[*i] != '\0')
		(*i)++;
	lexer = add_new_lexer(lexer, ft_strdup2(str, *old_i, *i));
	*old_i = *i;
	return (lexer);
}

// t_lexer *add_flag_token(char *str, int *i, int *old_i, t_lexer *lexer)
{
	if (str[*i] != '-')
		return (lexer);
	(*i)++;
	while (str[*i] != '\0')
	{
		if (ft_isalpha(str[*i]) == 0)
			break ;
		(*i)++;
	}
	lexer = add_new_lexer(lexer, ft_strdup2(str, *old_i, *i));
	*old_i = *i;
	return (lexer);
}

t_lexer	*split_elements(char *str, t_lexer *lexer) // check if index returned by functions is correct
{
	int	i;
	int	old_i;

	i = 0;
	while (str[i] != '\0')
	{
		old_i = i;
		lexer = add_quote_token(str, &i, &old_i, lexer);
		lexer = add_word_token(str, &i, &old_i, lexer);
		lexer = add_redirection_token(str, &i, &old_i, lexer);
		// lexer = add_flag_token(str, &i, &old_i, lexer);
		i = skip_spaces(str, i);
	}
	print_lexer(lexer);
	return (lexer);
}

void	tokenize(char **str_arr)
{
	int	i;
	t_lexer	*lexer;

	i = 0;
	lexer = NULL;
	while (str_arr[i] != NULL)
	{
		lexer = split_elements(str_arr[i++], lexer);
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


// t_lexer	*split_elements(char *str, t_lexer *lexer) // check if index returned by functions is correct
// {
// 	int	i;
// 	int	old_i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		old_i = i;
// 		add_quote_token(str, &i, &old_i, lexer);
// 		if (old_i != i)
// 		{
// 			lexer = add_new_lexer(lexer, ft_strdup2(str, old_i, i));
// 			old_i = i;
// 		}
// 		i = add_word_token(str, i);
// 		if (old_i != i)
// 		{
// 			lexer = add_new_lexer(lexer, ft_strdup2(str, old_i, i));
// 			old_i = i;
// 		}	
// 		i = add_redirection_token(str, i);
// 		if (old_i != i)
// 			lexer = add_new_lexer(lexer, ft_strdup2(str, old_i, i));
// 		i = skip_spaces(str, i);
// 	}
// 	return (lexer);
// }

// void	tokenize(char **str_arr)
// {
// 	int	i;
// 	t_lexer	*lexer;

// 	i = 0;
// 	lexer = NULL;
// 	while (str_arr[i] != NULL)
// 	{
// 		split_elements(str_arr[i++], lexer);
// 		printf("\n");
// 	}
	
// }
