/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:09:42 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/20 15:10:03 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_cmd_tbl(t_cmd_tbl *cmd_tbl)
{
	if (cmd_tbl == NULL)
		return ;
	printf("CMD: %s\n", cmd_tbl->cmd);
	printf("ARGS: ");
	print_tokens(cmd_tbl->args);
	printf("REDIRECTIONS: ");
	print_tokens(cmd_tbl->redirs);
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

t_cmd_tbl	*get_last_cmd_tbl(t_cmd_tbl *cmd_tbl)
{
	t_cmd_tbl	*curr;

	if (cmd_tbl == NULL)
		return (NULL);
	curr = cmd_tbl;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

t_cmd_tbl	*add_new_cmd_tbl(t_cmd_tbl *cmd_tbl, t_cmd_tbl *new)
{
	t_cmd_tbl	*curr;

	curr = cmd_tbl;
	if (cmd_tbl == NULL)
		return (new);
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return (cmd_tbl);
}
