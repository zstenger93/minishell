/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:34:36 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/01 10:31:00 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	leaks()
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **env)
{	
	t_shell	shell;

	// atexit(&leaks);
	how_to_use(argc);
	init_shell(&shell, env);
	signals();
	shell_loop(&shell);
	free_at_exit(&shell);
	exit(shell.exit_code);
}
