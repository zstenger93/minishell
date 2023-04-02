/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:17:12 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 22:04:56 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	has_invalid_chars(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '^')
			return (TRUE);
		if (str[i] == 43 || str[i] == 61 || str[i] == 95 || (str[i] >= 65
				&& 122 >= str[i]) || (str[i] >= 48 && 57 >= str[i]))
		{
			if (str[i] == 43)
			{
				if (str[i + 1] == 61)
					return (FALSE);
				return (TRUE);
			}
			else if (str[i] == 61)
				return (FALSE);
			i++;
		}
		else
			return (TRUE);
	}
	return (FALSE);
}

bool	unset_special(t_shell *shell, char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		if (ft_strlen(args[i]) == 0 || args[i][0] == '?' || args[i][0] == '$')
		{
			shell->exit_code = 1;
			if (shell->print == TRUE)
				p_err("%s%s: `%s': %s\n", SHELL, args[0], args[i], NVI);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

bool	has_plus(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+')
		{
			if (str[i + 1] == '=')
				return (FALSE);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
