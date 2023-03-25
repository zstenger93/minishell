/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:57 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/25 10:15:11 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parser(t_shell *shell)
{
	char	**tokens;
	int		start;
	int		end;
	int		index;

	end = -1;
	start = 0;
	index = -1;
	tokens = split_with_pipes(shell->trimmed_prompt, start, end, index);
	shell->cmd_tbls = create_cmd_table(tokens);
	free_char_array(tokens);
}

char	**split_with_pipes(char *str, int start, int end, int index)
{
	char	**tokens;
	char	*tmp;

	tokens = malloc(sizeof(char *) * (count_pipes(str) + 1));
	if (tokens == NULL)
		return (p_err("%s%s\n", SHELL, MALLOC_FAIL), NULL);
	while (str[++end] != '\0')
	{
		end = skip_quotes(str, end);
		if (str[end] == '|'
			&& nb_esc_chars(str, end) % 2 == 0)
		{
			tmp = ft_strdup2(str, start, end);
			tokens[++index] = ft_strtrim(tmp, SPACES);
			free(tmp);
			start = end + 1;
		}
	}
	tmp = ft_strdup2(str, start, end);
	tokens[++index] = ft_strtrim(tmp, SPACES);
	tokens[++index] = NULL;
	return (free(tmp), tokens);
}

int	skip_quotes(char *str, int index)
{
	int	quote;

	if (str[index] != SQUOTE && str[index] != DQUOTE)
		return (index);
	quote = str[index++];
	while (str[index] != quote
		&& nb_esc_chars(str, index) % 2 == 1)
		index++;
	return (index + 1);
}

int	count_pipes(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		i = skip_quotes(str, i);
		if (str[i] == '|'
			&& nb_esc_chars(str, i) % 2 == 0)
			count++;
	}
	return (count + 1);
}
