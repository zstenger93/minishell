/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:46:37 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/11 15:18:46 by zstenger         ###   ########.fr       */
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

# define OPERATORS "|><"

typedef struct s_token
{
	char			*cmd;
	char			*args;
	char			*dollar;
	char			*operator;
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
	t_env	*env_head;
	char	*user_name;
	char	**cmd_paths;
	char	*prev_prompt;
	char	*trimmed_prompt;
	char	*terminal_prompt;
	t_token	**tokens;
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

//INITIALIZE
char	*extract_user(t_shell *shell);
void	init_shell(t_shell *shell, char **env);
void	init_missing_environment(t_shell *shell, char **env);

//SIGNALS
void	signals(void);
void	handle_sigint(int sig_num);

//LEXER
void	print_token(t_token *tokens);
void	identify_tokens(t_shell *shell);
void	free_token_array(t_token **array);
char	*ft_strdup2(char *str, int start, int end);
void	free_tokens(t_token *token, t_token **tokens);

//EXPANDER
bool	is_dollar(char *token);
char	*variable_doesnt_exist();
char	*var_to_expand(t_token *tokens);
char	*expand_variable(char *content);
char	*expand(char *token, t_shell *shell);
void	expander(t_token *token, t_shell *shell);
char	*replace_variable(char *variable, t_shell *shell);
void	replace_var_with_content(t_token *token, char *token_to_expand, char *content);

//CLEANUP TOOLS
void	free_env(t_env *head);
void	free_at_exit(t_shell *shell);
void	free_char_array(char **array);

//what does the philosopher pigeon say?
//TO BE OR NOT TO BE
void	ft_print_2d_char_array(char **array_2d);
void	print_to_stderr(char *str);
void	clear_screen(void);

#endif