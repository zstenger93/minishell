/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:34:36 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/03 12:11:39 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{	
	t_shell	shell;

	how_to_use(argc);
	init_shell(&shell, env);
	shell_loop(&shell);
	free_at_exit(&shell);
	exit(shell.exit_code);
}
