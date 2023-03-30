/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:47:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/30 11:25:21 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	dont_expand(char *str, int i)
{
	int	sq;
	int	dq;

	sq = 0;
	dq = 0;
	if (i == 0)
		return (FALSE);
	if (str[i - 1] == SQUOTE)
	{
		while (i != -1)
		{
			if (str[i] == SQUOTE)
				sq++;
			if (str[i] == DQUOTE)
				dq++;
			i--;
		}
	}
	if (sq == 1 && dq == 0)
		return (TRUE);
	else if (sq == 1 && dq == 1)
		return (FALSE);
	else if (sq == 2 && dq == 2)
		return (TRUE);
	else if (sq == 4 && dq == 3)
		return (TRUE);
	return (FALSE);
}
