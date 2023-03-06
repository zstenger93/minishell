/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:02:03 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/06 12:27:31 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void    exit_shell(t_shell *shell)
{
    int     i;
    int     len;
    int     code;
    char    *code_str;

    if (ft_strcmp(shell->prompt, "exit") == 1
        && ft_strncmp(shell->prompt, "exit ", 5) != 0)
	{
		free_at_exit(shell);
		exit(EXIT_SUCCESS);
	}
    else if (ft_strncmp(shell->prompt, "exit ", 5) == 0)
    {
		printf("asd");
        i = 5;
        len = ft_strlen(shell->prompt + i);
        code_str = (char *)malloc(sizeof(char) * (len + 1));
		strcpy(code_str, shell->prompt + i);
		code = ft_atoi(code_str);
		free(code_str);
		free_at_exit(shell);
		exit(code);
    }
}
