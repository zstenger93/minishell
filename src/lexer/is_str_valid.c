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
	if (count_quotes(str, SQUOTE, DQUOTE) == FALSE)
		return (false);
	if (is_operator(str[0]) || is_operator(str[ft_strlen(str) - 1]))
		return (syntax_error(str[0]), false);
	while (str[++i])
	{
		if (is_operator(str[i]) && is_operator(str[i - 1]) && str[i] != str[i - 1])
			return (syntax_error(str[i]), false);
		if (is_operator(str[i]) && is_operator(str[i - 1]) && str[i] == '|' && str[i - 2] != 92)
			return (syntax_error(str[i]), false);
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
	return (true);
}

char	count_quotes(char *s, int sq, int dq)
{
	int		scount;
	int		qcount;
	int	i;

	i = -1;
	scount = 0;
	qcount = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == 92 && s[i + 1] != '\0' && (s[i + 1] == sq || s[i + 1] == dq))
			i++;
		else if (s[i] == sq)
			scount++;
		else if (s[i] == dq)
			qcount++;
	}
	if ((qcount % 2) == 0 && (scount % 2) == 0)
		return(1);
	syntax_error(s[i]);
	return (0);
}

bool	syntax_error(char c)
{
	
	return(ft_printf(BOLD"%s `%c'\n"C_END, SYNTAX_ERROR, c), false);
}

bool	is_operator(char c)
{
	return (ft_pf_strchr(OPERATORS, c));
}

bool	is_space(char c)
{
	return (ft_pf_strchr(SPACES, c));
}
