/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:33:39 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/20 17:55:12 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_tokens(t_token *token)
{
	t_token	*curr;
	
	curr = token;
	while (curr != NULL)
	{
		printf("%s ", curr->content);
		// printf("%s: %d\n", curr->content, curr->type);
		curr = curr->next;
	}
	printf("\n");
}

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
