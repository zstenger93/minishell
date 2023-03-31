/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:47:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 21:01:14 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	dont_expand(char *str, int i)
{
	int		j;
	int		sq;
	int		dq;
	bool	go_back;

	sq = 0;
	dq = 0;
	go_back = false;
	if (i == 0)
		return (FALSE);
	j = i;
	if (i > 0 && (str[i + 1] == DQUOTE || str[i + 1] == SQUOTE))
		return (TRUE);
	while (j != 0)
	{
		if (str[j] == SQUOTE || str[j] == DQUOTE)
			go_back = false;
		j--;
	}
	if (go_back == false)
		if (dont_expand_result(str, i, dq, sq) == TRUE)
			return (TRUE);
	return (FALSE);
}

bool	dont_expand_result(char *str, int i, int dq, int sq)
{
	int	j;

	j = i;
	while (i != -1)
	{
		if (str[i] == SQUOTE && nb_esc_chars(str, i) % 2 == 0)
			sq++;
		if (str[i] == DQUOTE && nb_esc_chars(str, i) % 2 == 0)
			dq++;
		i--;
	}
	if (sq == 1 && dq == 0)
		return (TRUE);
	else if (sq == 1 && dq == 1 && str[j - 1] == DQUOTE)
		return (TRUE);
	else if (sq == 2 && dq == 1)
		return (FALSE);
	else if (sq == 1 && dq == 2 && str[j - 1] == SQUOTE)
		return (TRUE);
	else if (sq == 2 && dq == 2 && str[j - 1] == SQUOTE && str[j - 3] == SQUOTE)
		return (TRUE);
	else if (sq == 4 && dq == 3)
		return (TRUE);
	return (FALSE);
}
