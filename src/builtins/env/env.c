/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:54:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/17 15:16:56 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	env(t_shell *shell)
{
	t_env	*curr;

	if (ft_strlen(shell->trimmed_prompt) > 3)
	{
		p_err("env: %s\n", TMA);
		return ;
	}
	curr = shell->env_head;
	while (curr != NULL)
	{
		if (curr->content == NULL)
			;
		else
			printf("%s=%s\n", curr->var_name, curr->content);
		curr = curr->next;
	}
}
