/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:57 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/11 16:32:57 by zstenger         ###   ########.fr       */
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

char	**get_operator_list()
{
	char	**result;

	result = malloc(sizeof(char *) * 5);
	if (result == NULL)
		printf("MALLOC ERROR\n");
	result[0] = ft_strdup("|");
	result[1] = ft_strdup("<");
	result[2] = ft_strdup(">");
	result[3] = ft_strdup(">>");
	result[4] = NULL;
	return (result);
}

bool	is_space(char c)
{
	return (ft_pf_strchr(SPACES, c));
}

bool	is_operator(char c)
{
	return (ft_pf_strchr(OPERATORS, c));
}

bool	wrong_operator_check(char *str) // case when cat Makefile <     > dasdas
{
	int	i;
	int	j;

	i = 0;
	if (is_operator(str[0]) || is_operator(str[ft_strlen(str) - 1]))
		return (false);
	while (str[++i])
	{
		if (is_operator(str[i]) && is_operator(str[i - 1]) && str[i] != str[i - 1])
			return (false);
		if (is_operator(str[i]) && is_operator(str[i - 1]) && str[i] == '|')
			return (false);
		if (is_operator(str[i - 1]) && is_space(str[i]))
		{
			j = i;
			while (is_space(str[j]))
			{
				if (is_operator(str[j + 1]))
					return (FALSE);
				j++;
				i++;
			}
		}
	}
	printf("CORRECT INPUT\n");
	return (true);
}


bool	is_operator_delimeter(char *str, int index)
{
	if (ft_pf_strchr(OPERATORS, str[index]) == NULL)
		return (false);
	else if (ft_pf_strchr(OPERATORS, str[index]) && str[index - 1] == 92)
		return (false);
	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index - 1]) == NULL
			&& ft_pf_strchr(OPERATORS, str[index + 1]) == NULL)
		return (true);
	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index + 1])
			&& str[index] != str[index + 1]) // if 2 characters in a row are operators && they arent't the same
	{
		printf("WRONG OPERATORS\n");
		return (false);
	}
	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index + 1])
			&& str[index] == str[index - 1] && str[index] == '>') // >>
		return (true);
	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index + 1]) == NULL)
		return (true);
	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index + 1]))
		return (false);
	return (false);
}

void	identify_tokens(t_shell *shell)
{
	// int		i;
	bool	result;

	// i = -1;
	// while (shell->trimmed_prompt[++i] != '\0')
	// {
	// 	result = is_operator(shell->trimmed_prompt, i);
	// 	printf("%c = %d\n", shell->trimmed_prompt[i], result);
	// }
	result = wrong_operator_check(shell->trimmed_prompt);
	if (result == false)
		printf("WRONG INPUT\n");
}




// in loop first token second statement just word
// void	identify_tokens(t_shell *shell)
// {
// 	int		i;
// 	int		start_token;
// 	bool	is_token;

// 	i = -1;
// 	is_token = FALSE;
// 	if (ft_pf_strchr(TOKENS, shell->trimmed_prompt[0]) != NULL)
// 		is_token = TRUE;
// 	start_token = 0;
// 	while (shell->trimmed_prompt[++i] != '\0')
// 	{
// 		if (shell->trimmed_prompt[i] == SQUOTE || shell->trimmed_prompt[i] == DQUOTE)
// 			i = skip_quotes(shell->trimmed_prompt, i + 1);
// 		if (ft_pf_strchr(TOKENS, shell->trimmed_prompt[i]) != NULL
// 			&& is_token == TRUE)
// 		{
// 			add_token(shell->tokens, ft_strdup2(shell->trimmed_prompt, start_token, i));
// 			start_token = i;
// 			is_token = FALSE;
// 		}
// 		else if (is_token == FALSE && ft_pf_strchr(TOKENS, shell->trimmed_prompt[i]) == NULL)
// 		{
// 			add_token(shell->tokens, ft_strdup2(shell->trimmed_prompt, start_token, i));
// 			is_token = TRUE;
// 			start_token = i;
// 		}
// 	}
// 	add_token(shell->tokens, ft_strdup2(shell->trimmed_prompt, start_token, i));
// }
// 	printf("Unexpected error near token '%c'", prompt[--i]);

		// if (ft_pf_strchr("$", shell->trimmed_prompt[i]) != NULL && shell->trimmed_prompt[i] != ')' && is_token == FALSE)
		// {
		// 	add_token(shell->tokens, ft_strdup2(shell->trimmed_prompt, start_token, i));
		// 	start_token = i;
		// 	is_token = TRUE;
		// }