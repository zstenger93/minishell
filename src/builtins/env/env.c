/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:54:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/07 15:59:46 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	env(t_shell *shell)
{
	t_env	*curr;

	if (ft_strlen(shell->trimmed_prompt) > 3)
	{
		ft_printf("env: too many arguments\n");
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
