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

//fix promt to origi
# define HERE_DOC "\033[1;34mheredoc> \033[0m"

//OWN HEADERS
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

//full env list saved in envp
typedef struct s_minishell
{
	char				**envp;
	struct s_minishell	*next;
}	t_minishell; 

typedef struct s_prompt
{
	char			*prompt_line;

}	t_prompt;

//paths to commands from PATH saved in paths
typedef struct s_path
{
	char			**paths;
	struct s_path	*next;
}	t_path;

void	terminal_prompt(char *type);
void	shell_loop(char **env_path, char **env);
char	**copy_env(char **env);
void	print_env(char **env_path, char *line);
char	*get_env(char **env);

#endif