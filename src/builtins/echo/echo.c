/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:01 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/26 12:48:21 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	echo_n_flag_validator(char **args);
bool	is_flag_valid(char *arg);

void	echo(t_shell *shell, char *cmd, char **args)
{
	int		i;
	char	*trim;

	if (shell->print == TRUE)
	{
		if (ft_strcmp(cmd, "echo") == TRUE && args[1] == NULL)
				write(1, "\n", 1);
		else if (ft_strcmp(cmd, "echo") == TRUE && is_flag_valid(args[1]) == TRUE)
		{
			i = echo_n_flag_validator(args);
			if (i == TRUE)
				write(1, "", 1);
			else
			{
				while (args[i] != NULL)
				{
					write(1, args[i], ft_strlen(args[i]));
					i++;
				}
			}
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

int	echo_n_flag_validator(char **args)
{
	int	i;

	i = 1;
	while (args[i + 1] != NULL)
	{
		if (is_flag_valid(args[i]) == TRUE)
			i++;
		else
			return (i);
	}
	if (ft_strncmp(args[i], "-n", 2) == 0)
	{
		if (is_flag_valid(args[i]) == TRUE)
			return (TRUE);
		else
			return (i);
	}
	return (i);
}

bool	is_flag_valid(char *arg)
{
	int	i;

	if (ft_strcmp(arg, "-n") == TRUE)
		return (TRUE);
	else if (ft_strncmp(arg, "-n", 2) == 0)
	{
		i = 1;
		while (arg[i] != '\0')
		{
			if (arg[i] == 'n')
				i++;
			else
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

//CAN BE DELETED PROBABLY
// bool	wrong_echo_cmd(t_shell *shell)
// {
// 	char	**shit_cmd;

// 	if (cmd(shell, "echo", 4) && ft_strlen(shell->trimmed_prompt) == 4)
// 	{
// 		write(1, "\n", 1);
// 		return (TRUE);
// 	}
// 	if (ft_strcmp(cmd, "echo") == FALSE)
// 	{
// 		shit_cmd = ft_split(shell->trimmed_prompt, ' ');
// 		p_err("%s: %s\n", shit_cmd[0], CMD_NOT_FND);
// 		shell->exit_code = 127;
// 		free_char_array(shit_cmd);
// 		return (TRUE);
// 	}
// 	return (FALSE);
// }

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
