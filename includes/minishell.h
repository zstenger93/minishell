/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:46:37 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/05 14:50:08 by zstenger         ###   ########.fr       */
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

typedef struct s_envp
{
	char			*start;
	char			*content;
	struct s_envp	*next;
}	t_envp;

typedef struct s_minishell
{
	char				*user;
	char				**envp;
	t_envp				*env;
	struct s_minishell	*next;
}	t_minishell;

typedef struct s_prompt
{
	char	*line;
	char	**sliced;

}	t_prompt;

//paths to commands from PATH saved in paths
typedef struct s_path
{
	char			**paths;
	struct s_path	*next;
}	t_path;

void	terminal_prompt(char *type);
void	shell_loop(char **env_path);
char	**copy_env(char **env);
void	print_env(char **env_path, char *line);
char	*get_env(char **env);
void	env_xprt_xt(char **env_path, char *prompt);

void	mini_pwd(char **env);
char	*get_user(char **env);


t_envp	*create_env(char **env);
t_envp	*new_node(char *envp, char *start, char *content);
// void	add_node_to_list(t_envp **env, t_envp *new);
void	add_node_to_list(t_envp *env, t_envp *new);

t_envp	*last_node(t_envp *env);

#endif