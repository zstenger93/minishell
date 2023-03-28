/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:01 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/28 10:33:51 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	echo(t_shell *shell, char *cmd, char **args)
{
	int		i;

	if (shell->print == TRUE)
	{
		if (ft_strcmp(cmd, "echo") == TRUE && args[1] == NULL)
			write(1, "\n", 1);
		else if (ft_strcmp(cmd, "echo") == TRUE
			&& is_flag_valid(args[1]) == TRUE)
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
			simple_echo(shell, args);
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

void	simple_echo(t_shell *shell, char **args)
{
	print_without_quotes(args[1]);
	write(1, "\n", 1);
}

//MAYBE IMPROVE THIS BEAUTY OVER HERE
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
