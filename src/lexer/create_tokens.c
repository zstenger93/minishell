/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:57 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/12 13:15:11 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	identify_tokens(t_shell *shell)
{
	// int		i;
	bool	result;

	result = wrong_operator_check(shell->trimmed_prompt);
	if (result == false)
		shell->exit_code = 1;
	// i = -1;
	// while (shell->trimmed_prompt[++i] != '\0')
	// {
	// 	result = is_operator(shell->trimmed_prompt, i);
	// 	printf("%c = %d\n", shell->trimmed_prompt[i], result);
	// }
	// 	printf("WRONG INPUT\n");
}































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

// bool	is_operator_delimeter(char *str, int index)
// {
// 	if (ft_pf_strchr(OPERATORS, str[index]) == NULL)
// 		return (false);
// 	else if (ft_pf_strchr(OPERATORS, str[index]) && str[index - 1] == 92)
// 		return (false);
// 	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index - 1]) == NULL
// 			&& ft_pf_strchr(OPERATORS, str[index + 1]) == NULL)
// 		return (true);
// 	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index + 1])
// 			&& str[index] != str[index + 1]) // if 2 characters in a row are operators && they arent't the same
// 	{
// 		printf("WRONG OPERATORS\n");
// 		return (false);
// 	}
// 	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index + 1])
// 			&& str[index] == str[index - 1] && str[index] == '>') // >>
// 		return (true);
// 	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index + 1]) == NULL)
// 		return (true);
// 	else if (ft_pf_strchr(OPERATORS, str[index]) && ft_pf_strchr(OPERATORS, str[index + 1]))
// 		return (false);
// 	return (false);
// }
