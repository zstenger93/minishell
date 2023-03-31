/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:33:39 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 19:53:04 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_tokens(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr != NULL)
	{
		printf("%s|", curr->content);
		curr = curr->next;
	}
	printf("\n");
}

void	print_cmd_tbl(t_cmd_tbl *cmd_tbl)
{
	t_cmd_tbl	*curr;

	if (cmd_tbl == NULL)
		return ;
	curr = cmd_tbl;
	while (curr != NULL)
	{
		printf("CMD: %s\n", curr->cmd);
		printf("ARGS: ");
		print_tokens(curr->args);
		printf("REDIRECTIONS: ");
		print_tokens(curr->redirs);
		ft_print_2d_char_array(curr->cmd_args);
		curr = curr->next;
	}
	printf("\n");
}

void	ft_print_2d_char_array(char **array_2d)
{
	int	i;

	if (array_2d == NULL)
		return ;
	i = 0;
	while (array_2d[i] != NULL)
		printf("%s\n", array_2d[i++]);
}
