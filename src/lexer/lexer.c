/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:17:09 by zstenger          #+#    #+#             */
/*   Updated: 2023/02/28 15:43:31 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer(char *prompt_line)
{
	t_prompt	line;
	
	if (count_quote(prompt_line, DQUOTE) != 0 || count_quote(prompt_line, SQUOTE) != 0)
		return(printf("%d\n%d\n", count_quote(prompt_line, DQUOTE), count_quote(prompt_line, SQUOTE)), 0);
	line.sliced = ft_split(prompt_line, ' ');
	int i = 0;
	while (line.sliced[i] != NULL)
	{
		if (ft_strncmp(line.sliced[i], HEREDOC, 2) == 0
			|| ft_strncmp(line.sliced[i], APPEND, 2) == 0
			|| ft_strncmp(line.sliced[i], PIPE, 1) == 0)
			printf("%s is a token\n", line.sliced[i]);
		else
			printf("%s\n", line.sliced[i]);
		i++;
	}
	free_char_array(line.sliced);
	return(0);
}

char	count_quote(const char *s, int c)
{
	int		count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}