/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:02:03 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/05 15:02:12 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	env_xprt_xt(char **env_path, char *prompt)
{
	if (ft_strncmp(prompt, "env", 3) == 0 || ft_strncmp(prompt, "export", 6) == 0)
		print_env(env_path, prompt);
	if (ft_strncmp(prompt, "command exit", 12) == 0 || ft_strncmp(prompt, "exit", 4) == 0)
	{
		if(ft_strncmp(prompt, "exit", 4) == 0)
		{
			free(prompt);
			//cleanup function
			clear_history();
			rl_clear_history();
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(prompt);
			ft_putendl_fd("exit", STDOUT_FILENO);
			//cleanup function
			clear_history();
			rl_clear_history();
			exit(EXIT_SUCCESS);
		}
		
	}
	if(prompt[0] != '\0')
		add_history(prompt);
	else
		printf("\n");
}