/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:58:28 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 19:04:57 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	is_exit_code_correct(t_shell *shell, char *args, int i)
{
	int	result;
	int	sign;

	result = 0;
	if (args[0] == '+')
		i = 1;
	if (args[0] == '-')
	{
		i = 1;
		sign = -1;
	}
	while (args[i] != '\0')
	{
		if (args[i] < '0' || args[i] > '9')
			return (FALSE);
		result = (result * 10) + (args[i] - '0');
		if (result > 255)
			result %= 256;
		i++;
	}
	if (sign == -1)
		result = 256 - result;
	shell->exit_code = result;
	return (TRUE);
}

void	exit_error_msg(t_shell *shell, char *cmd, char *arg, int option)
{
	if (option == 0)
	{
		p_err("%s%s: %s\n", SHELL, arg, NAR);
		shell->exit_code = 255;
	}
	else
	{
		p_err("%s%s: %s\n", SHELL, cmd, TMA);
		shell->exit_code = 1;
	}
}
