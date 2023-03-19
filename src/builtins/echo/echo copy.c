/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:01 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/19 08:24:34 by zstenger         ###   ########.fr       */
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
			print_with_quotes(trim);
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

int	sq_space_counter(char *str, int i, int sq_space)
{
	if (str[i] == '\'')
		return (sq_space + 1);
	return (sq_space);
}

int	dq_space_counter(char *str, int i, int dq_space, int dq)
{
	if (str[i] == '\"')
	{
		dq++;
		dq_space++;
		return (dq_space);
	}
	return (dq_space);
}

//eChO "FuCk'EcHo" does print last "
void	print_with_quotes(char *str)
{
	int	i;
	int	dq;
	int	quotes;
	int	dq_space;
	int	sq_space;

	i = 0;
	dq = 0;
	dq_space = 0;
	quotes = has_quote_in_string(str);
	while (str[i] != '\0' && print_without_quotes(str) == FALSE)
	{
		sq_space = sq_space_counter(str, i, sq_space);
		dq_space = dq_space_counter(str, i, dq_space, dq);
		if (str[i] == '\"')
			dq = 1;
		if (str[i] == ' ' && str[i + 1] == ' ' && quotes == FALSE)
			while (str[i] == ' ')
				i++;
		if ((str[i] != '\"' && dq_space % 2 != 0)
			|| (str[i] != '\'' && sq_space % 2 != 0))
			write(1, &str[i], 1);
		else if (str[i] == '\'')
			if (dq == 1)
				write(1, &str[i], 1);
		i++;
	}
}

bool	print_without_quotes(char *str)
{
	int	i;
	int	dq;
	int	quotes;

	i = 0;
	dq = 0;
	quotes = has_quote_in_string(str);
	while (str[i] != '\0' && quotes == FALSE)
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
	if (quotes == FALSE)
		return (TRUE);
	return (FALSE);
}