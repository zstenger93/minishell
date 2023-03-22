/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:41:43 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/22 18:02:48 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	nb_esc_chars(char *str, int last_ind)
{
	int	count;

	count = 0;
	while (--last_ind != -1)
	{
		if (str[last_ind] == 92)
			count++;
		if (str[last_ind] != 92)
			return (count);
	}
	return (count);
}

bool	is_special_char(char c)
{
	return (ft_pf_strchr(SPECIAL_CHARSET, c));
}

bool	syntax_error(char c)
{
	return (p_err(BOLD"%s `%c'\n"C_END, SYNTAX_ERROR, c), TRUE);
}

bool	syntax_error_newline(void)
{
	return (p_err(BOLD"%s%s\n"C_END, SHELL, SYNTAX_ERROR_NEWLINE), TRUE);
}

bool	is_operator(char c)
{
	return (ft_pf_strchr(OPERATORS, c));
}
