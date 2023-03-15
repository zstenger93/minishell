/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:01 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/15 13:47:20 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	echo(t_shell *shell)
{
	char	*trim;
	if (cmd(shell, "echo", 4) && ft_strlen(shell->trimmed_prompt) == 4)
		write(1, "\n", 1);
	else if (shell->trimmed_prompt[4] != ' ')
		printf("command not found\n");
	trim = ft_strtrim2(shell->trimmed_prompt, "echo ");
	trim_quotes(trim);
	free(trim);
}

void	trim_quotes(char *str)
{
	int	i;
	int dq;

	dq = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
			dq = 1;
		if (str[i] != '\"' && str[i] != '\'')
			write(1, &str[i], 1);
		else if (str[i] == '\'')
			if (dq == 1)
				write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

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

char	*ft_strtrim2(char const *s1, char const *set)
{
	char	*trim_result;
	size_t	z;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	// while (end > start && ft_char_in_set(s1[end - 1], set))
	// 	end--;
	trim_result = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!trim_result)
		return (NULL);
	z = 0;
	while (start < end)
		trim_result[z++] = s1[start++];
	trim_result[z] = '\0';
	return (trim_result);
}