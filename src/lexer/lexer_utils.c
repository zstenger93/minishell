/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:54:07 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/12 16:35:43 by zstenger         ###   ########.fr       */
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
