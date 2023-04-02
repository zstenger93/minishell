/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:01 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 15:21:18 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	echo(t_shell *shell, char *cmd, char **args)
{
	if (shell->print == TRUE)
	{
		shell->exit_code = 0;
		if (ft_strcmp(cmd, "echo") == TRUE && args[1] == NULL)
			write(1, "\n", 1);
		else if (is_flag_valid(args[1]) == TRUE)
			handle_n_flag(args);
		else
			simple_echo(shell, args);
	}
}

void	handle_n_flag(char **args)
{
	int	j;

	j = echo_n_flag_validator(args);
	if (j == TRUE)
		write(1, "", 1);
	else
	{
		while (args[j] != NULL)
		{
			print_without_quotes(args[j], 0, 0, 0);
			if (args[j + 1] != NULL)
				write(1, " ", 1);
			j++;
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

/*
writes the spaces between argumetns if they are not empty
or there is more than one arg with spaces
*/
void	simple_echo(t_shell *shell, char **args)
{
	int	j;

	j = 1;
	while (args[j] != NULL)
	{
		print_without_quotes(args[j], 0, 0, 0);
		if (args[j + 1] != NULL && space_filled_token(args[j]) != TRUE)
			write(1, " ", 1);
		else if (args[j + 1] != NULL && space_filled_token(args[j]) == TRUE
			&& space_filled_token(args[j + 1]) == TRUE)
			write(1, " ", 1);
		j++;
	}
	write(1, "\n", 1);
}
