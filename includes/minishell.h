/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:46:37 by zstenger          #+#    #+#             */
/*   Updated: 2023/02/26 18:36:13 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE 1
# define FALSE 0

# include "error.h"
# include "colors.h"
# include "cleanup.h"
# include "../libft/includes/libft.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_minishell
{
	char				**envp;
	struct s_minishell	*next;
}	t_minishell; 

typedef struct s_token
{
	char			*prompt_line;

}	t_token;

typedef struct s_path
{
	char			**paths;
	struct s_path	*next;
}	t_path;

void	terminal_prompt(char *type);
void	shell_loop(char **env_path, char **env);
char	**copy_env(char **path);
void	print_env(char **env_path, char *line);
char	*get_env(char **env);
void	free_char_array(char **array);

#endif