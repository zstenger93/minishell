
#ifndef LEXER_H
# define LEXER_H

// << >> < > | '' ""
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

//line -> current line from readline
typedef struct s_lexer
{

	t_token	token;
}

#endif