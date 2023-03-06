/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:38:18 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/06 12:30:54 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void    pwd(t_shell *shell)
{
    t_env   *curr;

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
