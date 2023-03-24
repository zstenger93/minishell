/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:22:11 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/24 19:09:49 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	execute(t_shell *shell, t_cmd_tbl *table)
{
	if (tables_have_wrong_redir(table, shell) == true)
		shell->exit_code = 258;
	// else
	// 	handle_heredocs(table, shell);
	if (table != NULL && table->next == NULL && table_size(table) == 1)
		exec_without_pipes(table, shell);
	else if (table != NULL && table->next != NULL)
		exec_pipes(table, shell);
}

int	table_size(t_cmd_tbl *table)
{
	int	i;

	i = 0;
	while (table != NULL)
	{
		i++;
		table = table->next;
	}
	return (i);
}

// void	handle_heredocs(t_cmd_tbl *table, t_shell *shell)
// {
// }
