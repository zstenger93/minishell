/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:17:09 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/12 09:30:36 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	lexer(char *prompt_line)
// {
// 	t_prompt	line;

// 	if(count_quotes(prompt_line, SQUOTE, DQUOTE) == 0)
// 		return(printf("odd amount of quotes\n"), 0);
// 	line.sliced = ft_split(prompt_line, ' ');
// 	int i = 0;
// 	while (line.sliced[i] != NULL)
// 	{
// 		if (ft_strncmp(line.sliced[i], HEREDOC, 2) == 0
// 			|| ft_strncmp(line.sliced[i], APPEND, 2) == 0
// 			|| ft_strncmp(line.sliced[i], PIPE, 1) == 0)
// 			printf("%s is a token\n", line.sliced[i]);
// 		else
// 			printf("%s\n", line.sliced[i]);
// 		i++;
// 	}
// 	free_char_array(line.sliced);
// 	return(0);
// }
