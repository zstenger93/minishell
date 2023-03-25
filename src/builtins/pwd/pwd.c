/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:38:18 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/25 18:21:44 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pwd(t_shell *shell, char **args)
{
	t_env	*curr;

	if (args[1] != NULL)
	{
		p_err("pwd: %s\n", TMA);
		return ;
	}
	curr = shell->env_head;
	if (find_env_var(shell->env_head, "PWD") == NULL)
	{
		shell->exit_code = 1;
		p_err("%spwd: %s\n", SHELL, PWNED);
	}
	while (curr->next != NULL)
	{
		if (ft_strncmp(curr->var_name, "PWD", 3) == 0)
		{
			printf("%s\n", curr->content);
			return ;
		}
		else
			curr = curr->next;
	}
}
