/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 08:16:47 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/21 09:58:51 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd_tbl	*init_cmd_table(t_cmd_tbl *cmd_tbls, t_token *tokens)
{
	t_cmd_tbl	*new;
	t_token		*curr;

	if (tokens == NULL)
		return (cmd_tbls);
	new = get_empty_cmd_table();
	printf("GOT AN EMPTY TABLE\n");
	curr = tokens;
	while (curr != NULL)
	{
		// printf("NEW TOKEN\n");
		curr = assign_cmd(new, curr);
		curr = assign_args(new, curr);
		curr = assign_redirs(new, curr);
	}
	new->cmd_args = get_cmd_args_from_token(new->cmd, new->args);
	cmd_tbls = add_new_cmd_tbl(cmd_tbls, new);
	return (cmd_tbls);
}

t_token	*assign_cmd(t_cmd_tbl *cmd_tbl, t_token *token)
{
	if (token == NULL)
		return (token);
	if (cmd_tbl->cmd != NULL || token->type != WORD)
		return (token);
	if (is_redirection(token->prev) == true)
		return (token);
	cmd_tbl->cmd = ft_strdup(token->content);
	return (token->next);
}

t_token	*assign_args(t_cmd_tbl *cmd_tbl, t_token *token)
{
	t_token	*new;

	if (token == NULL)
		return (token);
	if (token->type != WORD)
		return (token);
	if (is_redirection(token->prev) == true)
		return (token);
	if (cmd_tbl->cmd == NULL)
		return (token);
	new = copy_token(token);
	cmd_tbl->args = add_new_token2(cmd_tbl->args, new);
	return (token->next);
}

t_token	*assign_redirs(t_cmd_tbl *cmd_tbl, t_token *token)
{
	t_token	*new;

	if (token == NULL)
		return (token);
	else if (is_redirection(token) == false && is_redirection(token->prev) == false)
		return (token);
	else if (is_redirection(token) == true || is_redirection(token->prev) == true)
	{
		new = copy_token(token);
		cmd_tbl->redirs = add_new_token2(cmd_tbl->redirs, new);
	}
	return (token->next);
}

char	**get_cmd_args_from_token(char *cmd, t_token *token)
{
	int		size;
	char	**result;
	int		i;

	size = token_list_size(token) + 1;
	result = malloc(sizeof(char *) * (size + 1));
	if (result == NULL)
		printf("get_cmd_args_from_token error\n");
	result[size] = NULL;
	result[0] = ft_strdup(cmd);
	i = 1;
	while (token != NULL && i < size)
	{
		result[i] = ft_strdup(token->content);
		token = token->next;
		i++;
	}
	return (result);
}
