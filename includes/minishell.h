/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:46:37 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/06 16:02:37 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//OWN HEADERS
# include "defines.h"
# include "builtins.h"
# include "executor.h"
# include "parser.h"
# include "expander.h"
# include "general_utils.h"
# include "lexer.h"
# include "error.h"
# include "colors.h"
# include "cleanup.h"
# include "../libft/includes/libft.h"

//STANDARD HEADERS
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

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
	char	*terminal_prompt;
}	t_shell;

//MAIN UTILS
bool	add_history_if(char *prompt, char *prev_prompt);

//SHELL_LOOP
void	temp_exit(t_shell *shell);
void	shell_loop(t_shell *shell);

//PROMPT
char	*get_curr_dir(void);
void	terminal_prompt(t_shell *shell);

//BUILTIN ENV
char	*get_path(char **env);
t_env	*init_env(char **env);
t_env	*init_env_node(char *str);
void	print_env_vars(t_env *head);
void	add_back_env_node(t_env	*head, t_env *new);

//BUILTIN EXPORT
void	export(t_shell *shell);
char	*get_variable(char *prompt);
void	export_new_env(t_env *head, t_env *new);

//INITIALIZE
void	init_shell(t_shell *shell, char **env);

//CLEANUP TOOLS
void	free_env(t_env *head);
void	free_char_array(char **array);

void	ft_print_2d_char_array(char **array_2d);

#endif