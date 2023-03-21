/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:46:37 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 17:58:58 by zstenger         ###   ########.fr       */
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
#  include <sys/wait.h>
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

typedef enum e_type
{
	WORD,
	HEREDOC,
	OUTPUT,
	APPEND,
	INPUT,
	UKNOWN
}	t_type;

typedef struct s_token
{
	t_type			type;
	struct s_token	*next;
	struct s_token	*prev;
	char			*content;
}	t_token;

typedef struct s_cmd_tbl
{
	char				*cmd;
	t_token				*args;
	struct s_cmd_tbl	*next;
	t_token				*redirs;
	char				**cmd_args;
}	t_cmd_tbl;

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
	int			fd[2];
	char		**env;
	char		*prompt;
	char		*heredoc;
	t_cmd_tbl	*cmd_tbls;
	t_env		*env_head;
	int			echo_flag;
	int			exit_code;
	char		*user_name;
	char		**cmd_paths;
	char		*prev_prompt;
	char		*trimmed_prompt;
	char		*terminal_prompt;
	int			cmd_has_been_executed;
}	t_shell;

//MAIN UTILS
int			cmd(t_shell *shell, char *str, int s);
bool		add_history_if(char *prompt, char *prev_prompt);

//SHELL_LOOP
int			*read_line(t_shell *shell);
void		shell_loop(t_shell *shell);
void		addhistory(t_shell *shell);
bool		is_builtin(t_shell *shell);

//PROMPT
char		*get_curr_dir(t_shell *shell);
void		terminal_prompt(t_shell *shell);

//BUILTINS
bool		builtins(t_shell *shell);

//BUILTIN ENV
void		env(t_shell *shell);
char		*get_path(char **env);
t_env		*init_env(char **env);
t_env		*init_env_node(char *str);
char		*get_full_env(t_env *env);
void		print_env_vars(t_env *head);
char		**env_list_to_char(t_env *env);
int			get_env_list_size(t_env *head);
void		add_back_env_node(t_env	*head, t_env *new);

//BUILTIN EXPORT
void		export(t_shell *shell);
char		*get_variable(char *prompt);
void		print_export(t_shell *shell);
int			count_equal_sign(t_shell *shell);
void		export_new_variables(t_shell *shell);
void		add_new_variable(t_shell *shell, char *str);
char		*get_env_content(char *full, char *var_name);
void		replace_var_content(t_shell *shell, char *str, char *var);

//BUILTIN UNSET
void		unset(t_shell *shell);
void		unset_all_vars(t_shell *shell);
void		delete_env_var(t_env *head, t_env *del);
t_env		*find_env_var(t_env *head, char *var_name);

//BUILTIN PWD
void		pwd(t_shell *shell);

//BUILTIN EXIT
void		exit_code(t_shell *shell);
void		exit_shell(t_shell *shell);
int			is_wrong_command(char *s, char c);

//BUILTIN CD
void		cd(t_shell *shell);
void		cd_home(t_shell *shell);
void		cd_oldpwd(t_shell *shell);
void		cd_forward(char *folder_path);
bool		strcmp_2(char *str1, char *str2);
void		add_oldpwd_to_env(t_shell *shell);
int			nb_delimited_words(char *s, char c);
void		cd_back(char *dotdot, char *folder_path);
void		update_pwd_and_oldpwd(t_shell *shell, char *old_pwd);

//BUILTIN ECHO
void		echo(t_shell *shell);
bool		is_in_dq(char *s, int i);
void		print_with_quotes(char *str);
bool		wrong_echo_cmd(t_shell *shell);
bool		has_quote_in_string(char *str);
void		print_without_quotes(char *str);
bool		slash_n_checker(const char *str, int i);
char		*trim_result_malloc(const char *s1, size_t start);
bool		no_space_after_n(const char *s1, int i, t_shell *shell);
char		*trim_echo(char const *s1, char const *set, size_t start);
bool		breaking_bad(const char *s1, size_t start, t_shell *shell);
char		*trim_slash_n(char const *s1, char const *t, size_t i, t_shell *s);

//INITIALIZE
char		*extract_user(t_shell *shell);
void		init_shell(t_shell *shell, char **env);
void		init_missing_environment(t_shell *shell, char **env);

//SIGNALS
void		signals(void);
void		handle_sigint(int sig_num);

//LEXER
bool		is_space(char c);
bool		is_operator(char c);
void		lexer(t_shell *shell);
bool		redir_check(char *str);
bool		is_special_char(char c);
bool		is_special_char(char c);
bool		has_wrong_pipe(char *str);
bool		special_char_check(char *str);
bool		redir_after(char *str, int i);
bool		special_char_check(char *str);
bool		redir_before(char *str, int i);
bool		wrong_operator_check(char *str);
char		count_quotes(char *s, int sq, int dq);
int			nb_esc_chars(char *str, int last_ind);
char		*ft_strdup2(char *str, int start, int end);

//PARSER
void		parser(t_shell *shell);
	//PIPE TOKENS
int			count_pipes(char *str);
int			skip_quotes(char *str, int index);
char		**split_with_pipes(char *str, int start, int end, int index);
	//COMMAND TABLE
t_cmd_tbl	*create_cmd_table(char **str_arr);
t_token		*split_elements_to_tokens(char *str, t_token *token);
	//INIT TABLE
char		**get_cmd_args_from_token(char *cmd, t_token *token);
t_token		*assign_cmd(t_cmd_tbl *cmd_tbl, t_token *token);
t_token		*assign_args(t_cmd_tbl *cmd_tbl, t_token *token);
t_token		*assign_redirs(t_cmd_tbl *cmd_tbl, t_token *token);
t_cmd_tbl	*init_cmd_table(t_cmd_tbl *cmd_tbls, t_token *tokens);
	// CMD TABLE UTILS
bool		is_printable(char c);
t_cmd_tbl	*get_empty_cmd_table(void);
int			token_list_size(t_token *token);
t_cmd_tbl	*add_new_cmd_tbl(t_cmd_tbl *cmd_tbl, t_cmd_tbl *new);
	//ADD TOKEN
t_token		*add_flag_token(char *str, int *i, int *old_i, t_token *token);
t_token		*add_word_token(char *str, int *i, int *old_i, t_token *token);
t_token		*add_quote_token(char *str, int *i, int *old_i, t_token *token);
t_token		*add_redirection_token(char *str, int *i, int *old_i, t_token *tk);
	//ADD TOKEN UTILS
t_token		*copy_token(t_token *token);
t_token		*get_new_token(char *str, t_type type);
t_token		*add_new_token2(t_token *tokens, t_token *new);
t_token		*add_new_token(t_token *lexer, char *str, t_type type);
	//TOKEN UTILS
void		free_tokens(t_token *token);
bool		is_redirection(t_token *token);
t_type		get_redirection_type(char *str, int start, int end);

//EXPANDER
char		*variable_doesnt_exist(void);
bool		dont_expand(char *str, int i);
char		*copy_variable(char *content);
char		*return_exit_status(t_shell *shell);
bool		expander(char **str, t_shell *shell);
bool		has_dollar(char *str, t_shell *shell);
char		*replace_variable(char *variable, t_shell *shell);
char		*expand_dollars(char *doll_to_exp, t_shell *shell);
char		*type_to_expand(char *dollar_to_expand, t_shell *shell);
void		copy_dollar_from_string(char **dst, char **s, int index);
void		extract_dollar(char **s, t_shell *sh, char **bef_doll, char **rest);

//CLEANUP TOOLS
void		free_env(t_env *head);
void		free_at_exit(t_shell *shell);
void		free_char_array(char **array);

//ERROR HANDLING
void		print_in(void);
void		print_shell(void);
void		how_to_use(int argc);
bool		syntax_error(char c);

//GENERAL UTILS
int			ft_isupper(char c);
bool		unclosed_quotes(char *str);
int			skip_spaces(char *str, int index);
bool		convert_to_lower(char *str, int until);

//EXECUTOR
void		execute(t_shell *shell, t_cmd_tbl *cmd_table);
void		exec_smpl_cmd(t_cmd_tbl *table, t_shell *shell);
void		smpl_child_process(t_cmd_tbl *table, t_shell *shell);

void		exec_on_pipeline(t_cmd_tbl *table, t_shell *shell);
void		exec_smple_cmd_wth_redir(t_cmd_tbl *table, t_shell *shell);
	//COMMAND HANDLING
char		*extract_path(t_shell *shell, char *command);
void		invalid_command(t_shell *shell, char *command);
	//PATH CHECK
int			path_check(char *cmd_path, t_shell *shell);
int			no_such_file_or_folder(char *command, t_shell *shell);
	//HANDLE REDIRECTIONS
int			handle_redirections(t_shell *shell);
int			open_file(t_type type, char *file_name, t_shell *shell);
	//HEREDOC
void		set_heredoc_to_null(t_shell *shell);
void		heredoc(t_shell *shell, char *delimeter);

//what does the philosopher pigeon say?
//TO BE OR NOT TO BE
void		print_tokens(t_token *lexer);
void		print_cmd_tbl(t_cmd_tbl *cmd_tbl);
void		ft_print_2d_char_array(char **array_2d);

void		free_at_child(t_shell *shell);

void		update_env(t_shell *shell);

#endif