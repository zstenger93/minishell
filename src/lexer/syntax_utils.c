/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:41:43 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/03 08:43:22 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	nb_esc_chars(char *str, int last_ind)
{
	int	i;
	int	count;

	i = last_ind - 1;
	count = 0;
	if (last_ind <= 0)
		return (count);
	while (str[i] != -1)
	{
		if (str[i] == 92)
			count++;
		else if (str[i] != 92)
			return (count);
		i--;
	}
	return (count);
}

bool	syntax_error(char c)
{
	return (p_err(BOLD"%s%s `%c'\n"C_END, SHELL, SYNTAX_ERROR, c), TRUE);
}

bool	syntax_error_newline(void)
{
	return (p_err(BOLD"%s%s\n"C_END, SHELL, SYNTAX_ERROR_NEWLINE), TRUE);
}

bool	is_operator(char c)
{
	return (ft_pf_strchr(OPERATORS, c));
}
