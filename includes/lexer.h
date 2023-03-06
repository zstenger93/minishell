/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:25:42 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/06 12:25:44 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

// << >> < > | '' ""
// typedef enum s_token
// {
// 	// HEREDOC,
// 	// APPEND,
// 	INPUT = '<',
// 	OUTPUT = '>',
// 	PIPE = '|',
// 	SQUOTE = '\'',
// 	DQUOTE = '\"'
// }	t_token;

//line -> current line from readline
typedef struct s_lexer
{
	void			*content;
	struct s_lexer	*next;
}	t_lexer;

int		lexer(char *prompt_line);
char	count_quotes(char *s, int sq, int dq);

#endif