/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 08:40:41 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/27 11:15:03 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	builtins(t_shell *shell, char *cmd, char **args)
{
	if (ft_strcmp(cmd, "export") == TRUE && shell->should_execute == TRUE)
		return (export(shell, cmd, args), TRUE);
	else if ((ft_strcmp(cmd, "cd") == TRUE
		|| ft_strcmp(cmd, "/usr/bin/cd") == TRUE)
		&& shell->exec_on_pipe == FALSE)
		return (cd(shell, cmd, args), TRUE);
	else if (((convert_to_lower(cmd, 3) && ft_strcmp(cmd, "pwd") == TRUE)
		|| (convert_to_lower(cmd, 8) && ft_strcmp(cmd, "/bin/pwd") == TRUE))
		&& shell->should_execute == TRUE)
		return (pwd(shell, args), TRUE);
	else if (((convert_to_lower(cmd, 3) && ft_strcmp(cmd, "env") == TRUE)
		|| (convert_to_lower(cmd, 12)
		&& ft_strcmp(cmd, "/usr/bin/env") == TRUE))
		&& shell->should_execute == TRUE)
		return (env(shell, args), TRUE);
	else if (ft_strcmp(cmd, "exit") == TRUE)
		return (exit_shell(shell, cmd, args), TRUE);
	else if (ft_strcmp(cmd, "unset") == TRUE && shell->should_execute == TRUE)
		return (unset(shell, cmd, args), TRUE);
	else if (((convert_to_lower(cmd, 4) && ft_strcmp(cmd, "echo") == TRUE)
		|| (convert_to_lower(cmd, 9) && ft_strcmp(cmd, "/bin/echo") == TRUE))
		&& shell->should_execute == TRUE)
		return (call_echo(shell, cmd, args), TRUE);
	return (FALSE);
}

void	call_echo(t_shell *shell, char *cmd, char **args)
{
	echo(shell, cmd, args);
	if (shell->exit_code != 127)
		shell->exit_code = 0;
	
}