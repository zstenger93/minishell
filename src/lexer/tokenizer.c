/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:57 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/15 08:11:30 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokenizer(t_shell *shell)
{
	char	**tokens;

	tokens = get_tokens(shell->trimmed_prompt);
	ft_print_2d_char_array(tokens);
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

char	**get_tokens(char *str)
{
	char	**tokens;
	int		start;
	int		end;
	int		index;
	char	*tmp;

	tokens = malloc(sizeof(char *) * (count_pipes(str) + 1));
	if (tokens == NULL)
		printf("MALLOC\n");
	end = -1;
	start = 0;
	index = -1;
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
	free(tmp);
	tokens[++index] = NULL;
	return (tokens);
}
