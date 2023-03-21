/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:09:42 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/21 12:25:36 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd_tbl	*add_new_cmd_tbl(t_cmd_tbl *cmd_tbl, t_cmd_tbl *new)
{
	t_cmd_tbl	*curr;

	if (cmd_tbl == NULL)
		return (new);
	curr = cmd_tbl;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return (cmd_tbl);
}

t_cmd_tbl	*get_empty_cmd_table()
{
	t_cmd_tbl	*cmd_tbl;

	cmd_tbl = malloc(sizeof(t_cmd_tbl));
	if (cmd_tbl == NULL)
		printf("get empty cmd table malloc error\n");
	cmd_tbl->cmd = NULL;
	cmd_tbl->cmd_args = NULL;
	cmd_tbl->args = NULL;
	cmd_tbl->redirs = NULL;
	cmd_tbl->next = NULL;
	return (cmd_tbl);
}

int	token_list_size(t_token *token)
{
	int		i;
	t_token	*curr;

	if (token == NULL)
		return (0);
	i = 0;
	curr = token;
	while (curr->next != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i + 1);
}

bool is_printable(char c)
{
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

// WTF ??? NEED IT ??
// 
// t_cmd_tbl	*get_last_cmd_tbl(t_cmd_tbl *cmd_tbl)
// {
// 	t_cmd_tbl	*curr;

// 	if (cmd_tbl == NULL)
// 		return (NULL);
// 	curr = cmd_tbl;
// 	while (curr->next != NULL)
// 		curr = curr->next;
// 	return (curr);
// }