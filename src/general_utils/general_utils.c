/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:44:08 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/16 10:36:59 by jergashe         ###   ########.fr       */
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
