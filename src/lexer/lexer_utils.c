/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:54:07 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 22:06:21 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup2(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
		return (p_err("%s%s\n", SHELL, MALLOC_FAIL), NULL);
	i = -1;
	while (start + ++i != end)
		result[i] = str[i + start];
	result[i] = '\0';
	return (result);
}

char	count_quotes(char *s, int sq, int dq)
{
	int	sq_count;
	int	dq_count;
	int	i;

	i = -1;
	sq_count = 0;
	dq_count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == sq || (s[i] == 92 && s[i + 1] != '\0'
				&& s[i + 1] == sq && nb_esc_chars(s, i) % 2 == 0))
		{
			if (is_in_dq(s, i) == FALSE)
				sq_count++;
		}
		else if (s[i] == dq || (s[i] == 92 && s[i + 1] != '\0'
				&& s[i + 1] == dq && nb_esc_chars(s, i) % 2 == 0))
			dq_count++;
	}
	if (sq_count % 2 != 0)
		return (syntax_error(sq), TRUE);
	else if (dq_count % 2 != 0)
		return (syntax_error(dq), TRUE);
	return (FALSE);
}

bool	is_in_dq(char *s, int i)
{
	int	surrounded;
	int	j;

	j = i;
	surrounded = 0;
	while (i-- > 1)
		if (s[i] == DQUOTE)
			surrounded = 1;
	while (s[j++] != '\0')
		if (s[j] == DQUOTE && surrounded == 1)
			surrounded = 2;
	if (surrounded == 2)
		return (TRUE);
	return (FALSE);
}

bool	has_quote_in_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

bool	unclosed_quotes(char *str)
{
	if (count_quotes(str, SQUOTE, DQUOTE) == TRUE)
		return (TRUE);
	return (FALSE);
}
