/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:44:08 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/22 17:58:06 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	skip_spaces(char *str, int index)
{
	while (str[index] != '\0'
		&& is_space(str[index]))
		index++;
	return (index);
}

int	ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool	is_space(char c)
{
	return (ft_pf_strchr(SPACES, c));
}

bool	convert_to_lower(char *str, int until)
{
	int	len;
	int	i;

	i = 0;
	len = strlen(str);
	while (i < len && i < until)
	{
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
		i++;
	}
	return (TRUE);
}

bool	is_builtin(t_shell *shell)
{
	if (cmd(shell, "export", 6) == TRUE)
		return (TRUE);
	else if (cmd(shell, "cd", 2) == TRUE)
		return (TRUE);
	else if (convert_to_lower(shell->trimmed_prompt, 3)
		&& cmd(shell, "pwd", 3) == TRUE)
		return (TRUE);
	else if (convert_to_lower(shell->trimmed_prompt, 3)
		&& cmd(shell, "env", 3) == TRUE)
		return (TRUE);
	else if (cmd(shell, "exit", 4) == TRUE)
		return (TRUE);
	else if (cmd(shell, "unset", 5) == TRUE)
		return (TRUE);
	else if (convert_to_lower(shell->trimmed_prompt, 4)
		&& cmd(shell, "echo", 4) == TRUE)
		return (TRUE);
	return (FALSE);
}
