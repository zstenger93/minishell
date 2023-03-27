/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:46:37 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/27 20:18:21 by zstenger         ###   ########.fr       */
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
#  include </home/linuxbrew/.linuxbrew/opt/readline/include/readline/history.h>
#  include </home/linuxbrew/.linuxbrew/opt/readline/include/readline/readline.h>
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

# define PIPE "|"
# define OPERATORS "|><"
# define REDIRECTIONS "><"
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
	char				*heredoc_name;
	int					index;
}	t_cmd_tbl;

typedef struct s_env
{
	struct s_env	*next;
	char			*content;
	char			*var_name;
}	t_env;

typedef struct s_fds
{
	int				fd[2];
	struct s_fds	*prev;
	struct s_fds	*next;
}	t_fds;

typedef struct s_shell
{
	int			print;
	t_fds		*pipe;
	char		**env;
	char		*prompt;
	char		*heredoc;
	t_cmd_tbl	*cmd_tbls;
	t_env		*env_head;
	int			exit_code;
	int			std_fds[2];
	char		*user_name;
	int			color_codes;
	char		**cmd_paths;
	char		*prev_prompt;
	int			exec_on_pipe;
	int			should_expand;
	int			should_execute;
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
bool		builtins(t_shell *shell, char *cmd, char **args);
void		call_echo(t_shell *shell, char *cmd, char **args);

//BUILTIN ENV
char		*get_path(char **env);
t_env		*init_env(char **env);
t_env		*init_env_node(char *str);
char		*get_full_env(t_env *env);
void		update_env(t_shell *shell);
void		print_env_vars(t_env *head);
char		**env_list_to_char(t_env *env);
int			get_env_list_size(t_env *head);
void		env(t_shell *shell, char **args);
void		add_back_env_node(t_env	*head, t_env *new);

//BUILTIN EXPORT
char		*get_variable(char *prompt);
void		print_export(t_shell *shell);
int			count_equal_sign(t_shell *shell);
void		add_new_variable(t_shell *shell, char *str);
char		*get_env_content(char *full, char *var_name);
void		export(t_shell *shell, char *cmd, char **args);
void		export_new_variables(t_shell *shell, char **args);
void		replace_var_content(t_shell *shell, char *str, char *var);

//BUILTIN UNSET
void		free_env_var(t_env *env);
void		delete_env_var(t_env *head, t_env *del);
t_env		*find_env_var(t_env *head, char *var_name);
void		unset_all_vars(t_shell *shell, char **args);
void		unset(t_shell *shell, char *cmd, char **args);

//BUILTIN PWD
void		pwd(t_shell *shell, char **args);

//BUILTIN EXIT
void		exit_code(t_shell *shell, char **args);
void		exit_code_on_pipe(t_shell *shell, char **args);
void		exit_shell(t_shell *shell, char *cmd, char **args);

//BUILTIN CD
void		cd_home(t_shell *shell);
void		cd_oldpwd(t_shell *shell);
void		cd_forward(char *folder_path);
bool		strcmp_2(char *str1, char *str2);
void		add_oldpwd_to_env(t_shell *shell);
int			nb_delimited_words(char *s, char c);
void		cd_back(char *dotdot, char *folder_path);
void		cd(t_shell *shell, char *cmd, char **args);
void		cd_tilde(t_shell *shell, char *folder_path);
void		update_pwd_and_oldpwd(t_shell *shell, char *old_pwd);

//BUILTIN ECHO
bool		is_in_dq(char *s, int i);
bool		is_flag_valid(char *arg);
bool		has_quote_in_string(char *str);
void		print_without_quotes(char *str);
int			echo_n_flag_validator(char **args);
void		simple_echo(t_shell *shell, char **args);
void		echo(t_shell *shell, char *cmd, char **args);
char		*trim_echo(char const *s1, char const *set, size_t start);

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
int			lexer(t_shell *shell);
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
t_cmd_tbl	*create_cmd_table(char **str_arr, t_shell *shell);
t_token		*split_elements_to_tokens(char *str, t_token *token);
	//INIT TABLE
t_token		*assign_cmd(t_cmd_tbl *cmd_tbl, t_token *token);
t_token		*assign_args(t_cmd_tbl *cmd_tbl, t_token *token);
t_token		*assign_redirs(t_cmd_tbl *cmd_tbl, t_token *token);
char		**get_cmd_args_from_token(char *cmd, t_token *token);
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
void		expand_table(t_cmd_tbl *table, t_shell *shell);
void		expand_tokens(t_token *tokens, t_shell *shell);
char		*get_right_cmd(t_cmd_tbl *table, t_shell *shell);
void		expand_tables(t_cmd_tbl *tables, t_shell *shell);
char		*replace_variable(char *variable, t_shell *shell);
char		*expand_dollars(char *doll_to_exp, t_shell *shell);
char		*type_to_expand(char *dollar_to_expand, t_shell *shell);
void		copy_dollar_from_string(char **dst, char **s, int index);
void		extract_dollar(char **s, t_shell *sh, char **bef_doll, char **rest);

//EXECUTOR
void		child_exit(t_shell *shell);
int			table_size(t_cmd_tbl *table);
void		close_and_dup(t_shell *shell);
void		execute(t_shell *shell, t_cmd_tbl *table);
void		exec_without_pipes(t_cmd_tbl *table, t_shell *shell);
	//EXECUTE CMD
void		clear_and_exit(t_shell *shell, char *cmd_path);
void		execute_command(t_cmd_tbl *table, t_shell *shell);
	//COMMAND HANDLING
char		*extract_path(t_shell *shell, char *command);
void		invalid_command(t_shell *shell, char *command);
	//PATH CHECK
int			path_check(char *cmd_path, t_shell *shell);
int			no_such_file_or_folder(char *command, t_shell *shell);
	//HANDLE REDIRECTIONS
t_token		*set_curr(t_token *curr);
bool		is_good_redirection(t_token	*token);
void		handle_redirections(t_shell *shell, t_cmd_tbl *table);
int			open_file(t_type type, char *file_name, t_shell *shell);
bool		has_wrong_redir(t_shell *shell, t_token *token, t_cmd_tbl *table);
bool		change_stdin_out(t_type type, int fd, t_shell *shell, int ret_val);
	//HEREDOC EXEC
char		*filename(t_cmd_tbl *table);
bool		cmd_tbl_has_heredoc(t_cmd_tbl *cmd_tbl);
void		handle_heredocs(t_cmd_tbl *cmd_tbl, t_shell *shell);
void		execute_heredocs(t_cmd_tbl *cmd_tbl, t_shell *shell);
char		*heredoc(t_cmd_tbl *cmd_tbl, char *stop_word, t_shell *shell);
		//OPEN HEREDOC
bool		is_last_heredoc(t_token *token, t_token *redirs);
int			open_heredoc(t_cmd_tbl *table, t_shell *shell, t_token *token);
	//PIPELINE
		//EXEC ONLY HEREDOC
bool		has_heredoc_and_wrong_redir(t_token *token);
bool		tables_have_wrong_redir(t_cmd_tbl *table, t_shell *shell);
void		run_only_heredocs(t_cmd_tbl *start, t_cmd_tbl *last, t_shell *shll);
		//EXEC PIPES
bool		pipe_has_redirs(t_token *token);
char		**copy_2d_char_array(char **array);
void		exec_pipes(t_cmd_tbl *table, t_shell *shell);
void		exec_last_pipe(t_cmd_tbl *table, t_shell *shell);
void		pipe_child_process(t_cmd_tbl *table, t_shell *shell);
void		final_exec(char *cmd_path, t_cmd_tbl *table, t_shell *shell);

//GENERAL UTILS
int			ft_isupper(char c);
bool		unclosed_quotes(char *str);
int			skip_spaces(char *str, int index);
bool		convert_to_lower(char *str, int until);

//ERROR HANDLING
void		print_in(void);
void		print_shell(void);
void		how_to_use(int argc);
bool		syntax_error(char c);
bool		syntax_error_newline(void);

//CLEANUP TOOLS
void		free_env(t_env *head);
void		free_at_exit(t_shell *shell);
void		free_at_child(t_shell *shell);
void		free_char_array(char **array);
void		free_cmd_tbls(t_cmd_tbl *cmd_tbls);

//what does the philosopher pigeon say?
//TO BE OR NOT TO BE
void		print_tokens(t_token *lexer);
void		print_cmd_tbl(t_cmd_tbl *cmd_tbl);
void		ft_print_2d_char_array(char **array_2d);

#endif