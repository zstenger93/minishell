/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:47:49 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/12 13:10:36 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//finish the error message
//check for valid reads, shouldnt read non existing memory with -1 and -2
bool	wrong_operator_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) == 0)
		;
	else if (count_quotes(str, SQUOTE, DQUOTE) == FALSE)
		return (FALSE);
	else if (is_operator(str[0]) || is_operator(str[ft_strlen(str) - 1]))
		return (syntax_error(str[0]), FALSE);
	while (str[++i])
	{
		if (is_operator(str[i]) && is_operator(str[i - 1]) && str[i] != str[i - 1])
			return (syntax_error(str[i]), FALSE);
		if (is_operator(str[i]) && is_operator(str[i - 1]) && str[i] == '|' && str[i - 2] != 92)
			return (syntax_error(str[i]), FALSE);
		if (is_operator(str[i - 1]) && is_space(str[i]))
		{
			j = i;
			while (is_space(str[j]))
			{
				if (is_operator(str[j + 1]))
					return (syntax_error(str[j + 1]), FALSE);
				j++;
				i++;
			}
		}
	}
	return (TRUE);
}

char	count_quotes(char *s, int sq, int dq)
{
	int		sq_count;
	int		dq_count;
	int	i;

	i = -1;
	sq_count = 0;
	dq_count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == 92 && s[i + 1] != '\0' && (s[i + 1] == sq || s[i + 1] == dq))
			i++;
		else if (s[i] == sq)
			sq_count++;
		else if (s[i] == dq)
			dq_count++;
	}
	if (sq_count % 2 != 0)
		syntax_error(sq);
	else if (dq_count % 2 != 0)
		syntax_error(dq);
	else
		return (1);
}

bool	syntax_error(char c)
{
	return(ft_printf(BOLD"%s `%c'\n"C_END, SYNTAX_ERROR, c), FALSE);
}

bool	is_operator(char c)
{
	return (ft_pf_strchr(OPERATORS, c));
}

bool	is_space(char c)
{
	return (ft_pf_strchr(SPACES, c));
}
