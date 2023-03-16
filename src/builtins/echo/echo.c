/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:01 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/16 14:55:10 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	echo(t_shell *shell)
{
	char	*trim;
	char	**shit_cmd;

	if (cmd(shell, "echo", 4) && ft_strlen(shell->trimmed_prompt) == 4)
		write(1, "\n", 1);
	else if (shell->trimmed_prompt[4] != ' ')
	{
		shit_cmd = ft_split(shell->trimmed_prompt, ' ');
		printf("%s: command not found\n", shit_cmd[0]);
		free_char_array(shit_cmd);
	}
	else
	{
		if (cmd(shell, "echo -n", 7) && ft_strlen(shell->trimmed_prompt) == 7)
			write(1, "", 1);
		else
		{
			trim = ft_strtrim2(shell->trimmed_prompt, " -n", 5);
			trim_quotes(trim);
			free(trim);
		}
		if (!cmd(shell, "echo -n", 7))
			write(1, "\n", 1);
	}
}

void	trim_quotes(char *str)
{
	int	i;
	int	dq;
	int	quotes;

	i = 0;
	dq = 0;
	quotes = has_quote_in_string(str);
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
			dq = 1;
		if (str[i] == ' ')
			write(1, &str[i], 1);
		if (str[i] == ' ' && str[i + 1] == ' ' && quotes == FALSE)
			while (str[i] == ' ')
				i++;
		if (str[i] != '\"' && str[i] != '\'')
			write(1, &str[i], 1);
		else if (str[i] == '\'')
			if (dq == 1)
				write(1, &str[i], 1);
		i++;
	}
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

bool	slash_n_checker(const char *str, int i)
{
	int	j;

	j = i + 1;
	while (str[j] != '\0' && str[i - 1] != 'n')
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

char	*ft_strtrim2(char const *s1, char const *set, size_t start)
{
	char			*trim_result;
	static size_t	z = 0;

	if (!s1 || !set)
		return (NULL);
	while ((s1[start] && ft_char_in_set(s1[start], set)) && s1[start] != '\0')
	{
		if (s1[start] == ' ')
			start++;
		if (s1[start] == '-' && s1[start + 1] == 'n')
			if (slash_n_checker(s1, start) == true)
				while (ft_pf_strchr(SPACES, s1[start]) != NULL
					&& s1[start] != '\0')
					start++;
		start++;
	}
	if (s1[start] != '\0')
		start--;
	trim_result = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) - start + 1));
	if (!trim_result)
		return (NULL);
	while (start < ft_strlen(s1))
		trim_result[z++] = s1[start++];
	trim_result[z] = '\0';
	return (trim_result);
}
