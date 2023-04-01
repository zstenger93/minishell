/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:29:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/04/01 10:06:54 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd_tbl	*create_cmd_table(char **str_arr, t_shell *shell)
{
	int			i;
	t_token		*token;
	t_cmd_tbl	*cmd_tbls;

	i = 0;
	cmd_tbls = NULL;
	while (str_arr[i] != NULL)
	{
		token = NULL;
		token = split_elements_to_tokens(str_arr[i++], token);
		cmd_tbls = init_cmd_table(cmd_tbls, token);
		free_tokens(token);
	}
	expand_tables(cmd_tbls, shell);
	rm_quotes_tables(cmd_tbls, shell);
	init_cmd_args(cmd_tbls);
	return (cmd_tbls);
}

void	init_cmd_args(t_cmd_tbl *tables)
{
	while (tables != NULL)
	{
		tables->cmd_args = get_cmd_args_from_token(tables->cmd, tables->args);
		tables = tables->next;
	}
}
