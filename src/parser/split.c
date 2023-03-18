/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:55:12 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/17 09:07:03 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	skip_quotes_2(char *str, int index, int *nb_elements)
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
// 			*nb_elements = *nb_elements + 1;
// 			return (index + 1);
// 		}
// 		index++;
// 	}
// 	*nb_elements = *nb_elements + 1;
// 	return (index);
// }

// int	skip_word(char *str, int index, int *nb_elements)
// {
// 	if (str[index] != '\0'
// 		&& (ft_isalpha(str[index]) || ft_isalnum(str[index])))
// 	{
// 		while ((ft_isalpha(str[index]) || ft_isalnum(str[index]))
// 			&& str[index] != '\0')
// 		{
// 			index++;
// 		}
// 		*nb_elements = *nb_elements + 1;
// 	}
// 	return (index);
// }

// int	skip_redirections(char *str, int index, int *nb_elements)
// {
// 	char	redirection;

// 	if (str[index] == '\0'
// 		|| ft_pf_strchr(REDIRECTIONS, str[index]) == NULL)
// 		return (index);
// 	redirection = str[index];
// 	while (str[index] == redirection
// 		&& str[index] != '\0')
// 		index++;
// 	*nb_elements = *nb_elements + 1;
// 	return (index);
// }


// void	split_elements(char *str) // check if index returned by functions is correct
// {
// 	int	i;
// 	int	old_i;
// 	int	nb_elements;
// 	t_lexer	*lexer;

// 	i = 0;
// 	nb_elements = 0;
// 	lexer = NULL;
// 	while (str[i] != '\0')
// 	{
// 		old_i = i;
// 		i = skip_quotes_2(str, i, &nb_elements);
// 		if (old_i != i)
// 		{
// 			lexer = add_new_lexer(lexer, ft_strdup2(str, old_i, i));
// 			old_i = i;
// 		}
// 		i = skip_word(str, i, &nb_elements);
// 		if (old_i != i)
// 		{
// 			lexer = add_new_lexer(lexer, ft_strdup2(str, old_i, i));
// 			old_i = i;
// 		}	
// 		i = skip_redirections(str, i, &nb_elements);
// 		if (old_i != i)
// 			lexer = add_new_lexer(lexer, ft_strdup2(str, old_i, i));
// 		i = skip_spaces(str, i);
// 	}
// 	print_lexer(lexer);
// }


// int	nb_elements(char *str) // check if index returned by functions is correct
// {
// 	int	i;
// 	int	nb_elements;

// 	i = 0;
// 	nb_elements = 0;
// 	// printf("STRING: %s\nLEN: %zu\n\n", str, ft_strlen(str));
// 	while (str[i] != '\0')
// 	{
// 		// printf("LOOP i = %d, NB: %d\n", i, nb_elements);
// 		i = skip_quotes_2(str, i, &nb_elements);
// 		// printf("\tQUOTES i = %d, NB: %d\n", i, nb_elements);
// 		i = skip_word(str, i, &nb_elements);
// 		// printf("\t\tWORD i = %d, NB: %d\n", i, nb_elements);
// 		i = skip_redirections(str, i, &nb_elements);
// 		// printf("\t\t\tREDIRECTIONS i = %d, NB: %d\n\n", i, nb_elements);
// 		i = skip_spaces(str, i);
// 		usleep(500000);
// 	}
// 	return (nb_elements);
// }


// char	**split_2(char *str, char *delimeters)
// {
	
// }


// int	skip_letters(char *str, int index, int *nb_elements)
// {
// 	while (ft_isalpha(str[index]))
// 		index++;
// 	*nb_elements = *nb_elements + 1;
// 	return (index - 1);
// }

// int	skip_char(char *str, int index, char ch)
// {
// 	while (str[index] == ch)
// 		index++;
// 	return (index - 1);
// }
// cat<<stop | grep"something" | wc -l>outFile