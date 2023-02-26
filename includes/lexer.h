
#ifndef LEXER_H
# define LEXER_H

typedef enum s_token
{
	HEREDOC;
	APPEND;
	INPUT;
	OUTPUT;
	PIPE;
	SQUOTE;
	DQUOTE;
}	t_token;

typedef struct s_lexer
{
	char	*line;
	t_token	token;
}

#endif