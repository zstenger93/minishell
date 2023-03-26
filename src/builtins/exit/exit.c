/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:02:03 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/26 14:43:52 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	exit_shell(t_shell *shell, char *cmd, char **args)
{
	if (shell->exec_on_pipe == FALSE)
	{
		if (ft_strcmp(cmd, "exit") == TRUE && args[1] == NULL)
		{
			free_at_exit(shell);
			exit(shell->exit_code);
		}
		else if (ft_strcmp(cmd, "exit") == TRUE && args[2] == NULL)
			exit_code(shell, args);
		else
		{
			p_err("exit: %s\n", TMA);
			return ;
		}
	}
	else if (ft_strcmp(cmd, "exit") == TRUE && args[2] == NULL)
		exit_code_on_pipe(shell, args);
}

void	exit_code(t_shell *shell, char **args)
{
	int		i;
	int		len;
	int		code;
	char	*code_str;

	i = 5;
	len = ft_strlen(args[1]);
	code_str = (char *)malloc(sizeof(char) * (len + 1));
	if (code_str == NULL)
	{
		free_at_exit(shell);
		exit(EXIT_FAILURE);
	}
	strcpy(code_str, args[1]);
	code = ft_atoi(code_str);
	free_at_exit(shell);
	free(code_str);
	exit(code);
}

void	exit_code_on_pipe(t_shell *shell, char **args)
{
	int		i;
	int		len;
	char	*code_str;

	i = 5;
	len = ft_strlen(args[1]);
	code_str = (char *)malloc(sizeof(char) * (len + 1));
	if (code_str == NULL)
	{
		free_at_exit(shell);
		exit(EXIT_FAILURE);
	}
	strcpy(code_str, args[1]);
	shell->exit_code = ft_atoi(code_str);
	free(code_str);
}
