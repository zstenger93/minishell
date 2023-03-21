/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:29:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/21 12:25:17 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd_tbl	*create_cmd_table(char **str_arr)
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
		// printf("\n");
	}
	// print_cmd_tbl(cmd_tbls);
	return (cmd_tbls);
}

// cat Makefile | grep word | wc -l > out
// cat Makefile file 2 | grep word | wc -l -r > out
// t_cmd_tbl	*create_cmd_table(char **str_arr)
// t_cmd_tbl	create_cmd_table(char str_arr)