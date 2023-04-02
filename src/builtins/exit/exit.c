/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:02:03 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 14:39:46 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	exit_shell(t_shell *shell, char *cmd, char **args)
{
	if (shell->exec_on_pipe == FALSE)
	{
		if (ft_strcmp(cmd, "exit") == TRUE && args[1] == NULL)
			simple_exit(shell);
		if (ft_strcmp(cmd, "exit") == TRUE && ft_strlen(args[1]) == 0)
			exit_tma(shell, cmd);
		else if (args[2] == NULL && args[1] != NULL)
			exit_code(shell, args);
		else if (shell->print == TRUE)
		{
			if (ft_isalpha(args[1][0]))
				exit_error_msg(shell, cmd, args[1], 0);
			else
				exit_error_msg(shell, cmd, args[1], 1);
			return ;
		}
	}
	else if (args[2] == NULL
		&& args[1] != NULL)
		exit_code_on_pipe(shell, args);
}

void	simple_exit(t_shell *shell)
{
	free_at_exit(shell);
	exit(0);
}

void	exit_tma(t_shell *shell, char *cmd)
{
	if (shell->print == TRUE)
		p_err("%s%s: %s\n", SHELL, cmd, TMA);
	free_at_exit(shell);
	exit(255);
}

void	exit_code(t_shell *shell, char **args)
{
	int		i;
	int		len;
	int		code;

	i = 5;
	len = ft_strlen(args[1]);
	if (is_exit_code_correct(shell, args[1], 0))
		code = shell->exit_code;
	else
	{
		code = 255;
		if (shell->print == TRUE)
			p_err("%s%s: %s", SHELL, args[0], NAR);
		free_at_exit(shell);
		exit(code);
	}
	code = shell->exit_code;
	free_at_exit(shell);
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
		if (shell->print == TRUE)
			p_err("%s%s\n", SHELL, MALLOC_FAIL);
		free_at_exit(shell);
		exit(EXIT_FAILURE);
	}
	strcpy(code_str, args[1]);
	shell->exit_code = ft_atoi(code_str);
	free(code_str);
	exit(shell->exit_code);
}
