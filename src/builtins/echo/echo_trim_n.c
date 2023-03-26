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


// TO BE CHECKED AND DELETED

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

//THIS CAN BE DELETED
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

char	*trim_slash_n(char const *s1, char const *t, size_t i, t_shell *s)
{
	char	*trim_result;
	size_t	z;

	if (!s1 || !t)
		return (NULL);
	while ((s1[i] && ft_char_in_set(s1[i], t)) && s1[i] != '\0')
	{
		if (s1[i] == ' ' || s1[i])
			i++;
		if (breaking_bad(s1, i, s) == TRUE)
			break ;
		if (s1[i] == '-' && s1[i + 1] == 'n' && s1[i + 2] != '-')
			if (slash_n_checker(s1, i) == true)
				while (ft_pf_strchr(SPACES, s1[i]) != NULL
					&& s1[i] != '\0')
					i++;
	}
	if (s1[i] != '\0')
		i--;
	z = 0;
	trim_result = trim_result_malloc(s1, i);
	while (i < ft_strlen(s1))
		trim_result[z++] = s1[i++];
	trim_result[z] = '\0';
	return (trim_result);
}

char	*trim_result_malloc(const char *s1, size_t start)
{
	char	*trim_result;

	trim_result = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) - start + 1));
	if (!trim_result)
		return (NULL);
	return (trim_result);
}

bool	slash_n_checker(const char *str, int i)
{
	int	j;

	j = i + 1;
	while (str[i] == '-' && str[j] != '\0' && str[i + 1] == 'n')
	{
		if (str[i] == '-')
		{
			while (str[j] == 'n')
				j++;
			if (ft_pf_strchr(SPACES, str[j]) == NULL)
				return (FALSE);
		}
		else if (str[j] != '\0' && ft_pf_strchr(SPACES, str[j]))
			return (TRUE);
		break ;
	}
	return (FALSE);
}
