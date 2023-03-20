/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:29:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/20 15:18:45 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokenize(char **str_arr)
{
	int			i;
	t_token		*token;
	t_cmd_tbl	*cmd_tbls;

	i = 0;
	cmd_tbls = NULL;
	while (str_arr[i] != NULL)
	{
		printf("TOKEN #%d\n", i+1);
		token = NULL;
		token = split_elements_to_tokens(str_arr[i++], token);
		cmd_tbls = init_cmd_table(cmd_tbls, token);
		print_cmd_tbl(cmd_tbls);
		free_tokens(token);
		printf("\n");
	}
}

t_token	*split_elements_to_tokens(char *str, t_token *token) // check if index returned by functions is correct
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
	// print_tokens(token);
	return (token);
}
