/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:01 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/17 15:17:53 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	echo(t_shell *shell)
{
	char	*trim;

	shell->echo_flag = 0;
	if (wrong_echo_cmd(shell) == TRUE)
		return ;
	else
	{
		if (cmd(shell, "echo -n", 7) && ft_strlen(shell->trimmed_prompt) == 7)
			write(1, "", 1);
		else if (cmd(shell, "echo -n", 7))
		{
			trim = trim_slash_n(shell->trimmed_prompt, " -n", 4, shell);
			print_without_quotes(trim);
			free(trim);
			if (shell->echo_flag == 1)
				write(1, "\n", 1);
		}
		else
		{
			trim = trim_echo(shell->trimmed_prompt, " ", 5);
			print_without_quotes(trim);
			free(trim);
			write(1, "\n", 1);
		}
	}
}

bool	wrong_echo_cmd(t_shell *shell)
{
	char	**shit_cmd;

	if (cmd(shell, "echo", 4) && ft_strlen(shell->trimmed_prompt) == 4)
	{
		write(1, "\n", 1);
		return (TRUE);
	}
	if (shell->trimmed_prompt[4] != ' ')
	{
		shit_cmd = ft_split(shell->trimmed_prompt, ' ');
		p_err("%s: %s\n", shit_cmd[0], CMD_NOT_FND);
		shell->exit_code = 127;
		free_char_array(shit_cmd);
		return (TRUE);
	}
	return (FALSE);
}

void	print_without_quotes(char *str)
{
	int	i;
	int	dq;
	int	quotes;

	i = 0;
	dq = 0;
	quotes = has_quote_in_string(str);
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
			dq = 1;
		if (str[i] == ' ' && str[i + 1] == ' ' && quotes == FALSE)
			while (str[i] == ' ')
				i++;
		if (str[i] != '\"' && str[i] != '\'')
			write(1, &str[i], 1);
		else if (str[i] == '\'')
			if (dq == 1)
				write(1, &str[i], 1);
		i++;
	}
}
