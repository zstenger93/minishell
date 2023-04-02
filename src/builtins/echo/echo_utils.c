/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:45:07 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 15:20:47 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	space_filled_token(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == DQUOTE || str[i] == SQUOTE || str[i] == ' ')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

//MAYBE IMPROVE THIS BEAUTY OVER HERE
void	print_without_quotes(char *str, int i, int k, int dq)
{
	int	q;

	q = has_quote_in_string(str);
	while (str[i] != '\0')
	{
		if (str[i] == DQUOTE)
			dq = 1;
		if ((str[i] == ' ' && str[i + 1] == ' ' && q == FALSE) || str[i] == 92)
			while (str[i] == ' ')
				i++;
		k = i;
		if (str[i] == 92)
		{
			while (str[k] == 92)
				k++;
			i = write_escapes(str, k, i);
		}
		if (str[i] != DQUOTE && str[i] != SQUOTE)
			write(1, &str[i], 1);
		else if (str[i] == SQUOTE)
			if (dq == 1)
				write(1, &str[i], 1);
		i++;
	}
}

int	write_escapes(char *str, int escp_nb, int i)
{
	int	k;

	if (escp_nb == 1)
		return (i + 1);
	k = escp_nb;
	if (escp_nb % 2 == 0)
		while (k-- != escp_nb / 2)
			write(1, "\\", 1);
	else
	{
		k = escp_nb;
		while (k-- != (escp_nb / 2) + 1)
			write(1, "\\", 1);
	}
	return (i + escp_nb);
}
