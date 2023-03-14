/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:46:37 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/14 18:29:14 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//OWN HEADERS
# include "lexer.h"
# include "error.h"
# include "parser.h"
# include "colors.h"
# include "defines.h"
# include "cleanup.h"
# include "builtins.h"
# include "executor.h"
# include "expander.h"
# include "general_utils.h"
# include "../libft/includes/libft.h"

//READLINE
# if defined (__APPLE__)
#  include <readline/history.h>
#  include <readline/readline.h>
# else
#  include </home/linuxbrew/.linuxbrew/opt/readline/include/readline/readline.h>
#  include </home/linuxbrew/.linuxbrew/opt/readline/include/readline/history.h>
# endif

//STANDARD HEADERS
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <limits.h>
# include <termios.h>

# define REDIRECTIONS "><"
# define PIPE "|"
# define OPERATORS "|><"
# define SPACES " \t\n\v\r\f"
# define SPECIAL_CHARSET "*()#@:;%`&{}"

typedef struct s_token
{
	char			*content;
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	char			*token;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_parser
{
}	t_parser;

typedef struct s_env
{
	struct s_env	*next;
	char			*content;
	char			*var_name;
}	t_env;

typedef struct s_shell
{
	char	*prompt;
	t_token	**tokens;
	t_env	*env_head;
	char	*exit_code;
	char	*user_name;
	char	**cmd_paths;
	char	*prev_prompt;
	char	*trimmed_prompt;
	char	*terminal_prompt;
	int		cmd_has_been_executed;
}	t_shell;

//MAIN UTILS
int		cmd(t_shell *shell, char *str, int s);
bool	add_history_if(char *prompt, char *prev_prompt);

//SHELL_LOOP
int		*read_line(t_shell *shell);
void	shell_loop(t_shell *shell);
void	addhistory(t_shell *shell);

//PROMPT
char	*get_curr_dir(t_shell *shell);
void	terminal_prompt(t_shell *shell);

//BUILTINS
void	builtins(t_shell *shell);

//BUILTIN ENV
void	env(t_shell *shell);
char	*get_path(char **env);
t_env	*init_env(char **env);
t_env	*init_env_node(char *str);
void	print_env_vars(t_env *head);
void	add_back_env_node(t_env	*head, t_env *new);

//BUILTIN EXPORT
void	export(t_shell *shell);
char	*get_variable(char *prompt);
void	print_export(t_shell *shell);
int		count_equal_sign(t_shell *shell);
void	export_new_variables(t_shell *shell);
void	add_new_variable(t_shell *shell, char *str);
char	*get_env_content(char *full, char *var_name);
void	replace_var_content(t_shell *shell, char *str, char *var);

//BUILTIN UNSET
void	unset(t_shell *shell);
void	unset_all_vars(t_shell *shell);
void	delete_env_var(t_env *head, t_env *del);
t_env	*find_env_var(t_env *head, char *var_name);

//BUILTIN PWD
void	pwd(t_shell *shell);

//BUILTIN EXIT
void	exit_code(t_shell *shell);
void	exit_shell(t_shell *shell);
int		is_wrong_command(char *s, char c);

//BUILTIN CD
void	cd_home(void);
void	cd(t_shell *shell);
void	cd_oldpwd(t_shell *shell);
void	cd_forward(char *folder_path);
bool	strcmp_2(char *str1, char *str2);
void	add_oldpwd_to_env(t_shell *shell);
int		nb_delimited_words(char *s, char c);
void	cd_back(char *dotdot, char *folder_path);
void	update_pwd_and_oldpwd(t_shell *shell, char *old_pwd);

//BUILTIN ECHO

//INITIALIZE
char	*extract_user(t_shell *shell);
void	init_shell(t_shell *shell, char **env);
void	init_missing_environment(t_shell *shell, char **env);

//SIGNALS
void	signals(void);
void	handle_sigint(int sig_num);

//LEXER
bool	is_space(char c);
bool	is_operator(char c);
void	lexer(t_shell *shell);
bool	is_special_char(char c);
bool	is_special_char(char c);
void	tokenizer(char *prompt);
bool	has_wrong_pipe(char *str);
bool	special_char_check(char *str);
bool	redir_after(char *str, int i);
bool	special_char_check(char *str);
bool	redir_before(char *str, int i);
bool	wrong_operator_check(char *str);
char	count_quotes(char *s, int sq, int dq);
int		nb_esc_chars(char *str, int last_ind);
char	*ft_strdup2(char *str, int start, int end);

//TOKENIZER
// void	print_token(t_token *tokens);
// void	free_token_array(t_token **array);
// void	free_tokens(t_token *token, t_token **tokens);

//PARSER

//EXPANDER
char	*variable_doesnt_exist(void);
char	*copy_variable(char *content);
bool	expander(char **str, t_shell *shell);
bool	has_dollar(char *str, t_shell *shell);
void	get_dollar(char **dst, char **s, int index);
char	*expand(char *dollar_to_expand, t_shell *shell);
char	*replace_variable(char *variable, t_shell *shell);
char	*expand_dollars(char *dollar_to_expand, t_shell *shell);
void	extract_dollar(char **s, t_shell *sh, char **bef_doll, char **rest);

//CLEANUP TOOLS
void	free_env(t_env *head);
void	free_at_exit(t_shell *shell);
void	free_char_array(char **array);

//ERROR HANDLING
void	how_to_use(int argc);
bool	syntax_error(char c);

//GENERAL UTILS
void	print_to_stderr(char *str);
bool	unclosed_quotes(char *str);
int		skip_spaces(char *str, int index);

//what does the philosopher pigeon say?
//TO BE OR NOT TO BE
void	ft_print_2d_char_array(char **array_2d);

char	*ft_strtok_r(char *str, char const *sep, char **saveptr);

#endif