/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:29:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/20 18:10:38 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	create_cmd_table(char **str_arr)
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
		// free(cmd_tbls);
		printf("\n");
	}
}
