
#ifndef LEXER_H
# define LEXER_H

# define HEREDOC	"<<"
# define APPEND		">>"
# define INPUT		"<"
# define OUTPUT		">"
# define PIPE		"|"
# define SQUOTE		39
# define DQUOTE		34

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