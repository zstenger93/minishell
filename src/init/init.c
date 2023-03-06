/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:17:42 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/06 13:24:39 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_shell(t_shell *shell, char **env)
{
	shell->env_head = init_env(env);
	shell->cmd_paths = ft_split(get_path(env), ':');
	shell->prev_prompt = NULL;
	shell->terminal_prompt = NULL;
	shell->user_name = getenv("USER");
}

void	ft_print_2d_char_array(char **array_2d)
{
	int	i;

	i = 0;
	while (array_2d[i] != NULL)
		printf("%s\n", array_2d[i++]);
}
