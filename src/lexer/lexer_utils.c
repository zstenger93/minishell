/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:54:07 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/13 17:43:35 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup2(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
	{
		printf("FT_STRDUP2\n");
		return (NULL);
	}
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
		if (s[i] == 92 && s[i + 1] != '\0'
			&& (s[i + 1] == sq || s[i + 1] == dq))
			i++;
		else if (s[i] == sq)
			sq_count++;
		else if (s[i] == dq)
			dq_count++;
	}
	if (sq_count % 2 != 0)
		return (syntax_error(sq), TRUE);
	else if (dq_count % 2 != 0)
		return (syntax_error(dq), TRUE);
	return (FALSE);
}

bool	unclosed_quotes(char *str)
{
	if (count_quotes(str, SQUOTE, DQUOTE) == TRUE)
		return (TRUE);
	return (FALSE);
}
