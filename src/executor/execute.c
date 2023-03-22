/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:22:11 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/22 15:44:48 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(t_shell *shell, t_cmd_tbl *cmd_table)
{
	if (cmd_table != NULL && cmd_table->next == NULL)
		exec_smpl_cmd(cmd_table, shell);
}
	// if (cmd_table->redirs != NULL)
	// 	exec_smple_cmd_wth_redir(shell, cmd_table);
	// else
	// 	exec_on_pipeline(shell, cmd_table);

// void	exec_on_pipeline(t_cmd_tbl *table, t_shell *shell)
// {
// }
