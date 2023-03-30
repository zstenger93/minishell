/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:01 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/30 21:38:22 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	space_filled_token(char *str);

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
					print_without_quotes(args[i]);
					if (args[i + 1] != NULL)
						write(1, " ", 1);
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
	int	i;

	while (args[i] != NULL)
	{
		print_without_quotes(args[i]);
		if (args[i + 1] != NULL && space_filled_token(args[i]) != TRUE)
			write(1, " ", 1);
		else if (args[i + 1] != NULL && space_filled_token(args[i]) == TRUE
			&& space_filled_token(args[i + 1]) == TRUE)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

bool	space_filled_token(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == DQUOTE || str[i] == SQUOTE || str[i] == ' ')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
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
		if (str[i] == DQUOTE) 
			dq = 1;
		if (str[i] == ' ' && str[i + 1] == ' ' && quotes == FALSE)
			while (str[i] == ' ')
				i++;
		if (str[i] != DQUOTE && str[i] != SQUOTE)
			write(1, &str[i], 1);
		else if (str[i] == SQUOTE)
			if (dq == 1)
				write(1, &str[i], 1);
		i++;
	}
}
