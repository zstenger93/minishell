/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:38:18 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/17 15:19:15 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pwd(t_shell *shell)
{
	t_env	*curr;

	if (ft_strlen(shell->trimmed_prompt) > 3)
	{
		p_err("pwd: %s\n", TMA);
		return ;
	}
	curr = shell->env_head;
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
