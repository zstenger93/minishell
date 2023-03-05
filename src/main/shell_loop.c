/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:51:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/05 14:52:12 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_loop(char **env_path)
{
	t_path		path;
	t_prompt	prompt;

	terminal_prompt("startup");
	while (TRUE)
	{
		prompt.line = readline("");
		env_xprt_xt(env_path, prompt.line);
		if (ft_strncmp(prompt.line, "pwd", 3) == 0)
			mini_pwd(env_path);
		lexer(prompt.line);
		free(prompt.line);
		terminal_prompt("in_loop");
	}
	clear_history();
	rl_clear_history();
}
