/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_trim_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:59:29 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/26 12:21:39 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	z;

	z = 0;
	while (set[z])
	{
		if (set[z] == c)
			return (1);
		z++;
	}
	return (0);
}

char	*trim_echo(char const *s1, char const *set, size_t start)
{
	char	*trim_result;
	size_t	z;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	trim_result = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!trim_result)
		return (NULL);
	z = 0;
	while (start < end)
		trim_result[z++] = s1[start++];
	trim_result[z] = '\0';
	return (trim_result);
}
