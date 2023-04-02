/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:17:42 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 18:38:55 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_shell(t_shell *shell, char **env)
{
	t_token	token;

	if (getenv("USER") == NULL)
		init_missing_environment(shell, env);
	else
	{
		shell->envless = FALSE;
		shell->color_codes = TRUE;
		shell->env_head = init_env(env);
		shell->user_name = getenv("USER");
		shell->cmd_paths = ft_split(get_path(env), ':');
	}
	shell->env = NULL;
	shell->exit_code = 0;
	shell->print = FALSE;
	shell->heredoc = NULL;
	shell->cmd_tbls = NULL;
	shell->prev_prompt = NULL;
	shell->trimmed_prompt = NULL;
	shell->terminal_prompt = NULL;
	shell->cmd_has_been_executed = TRUE;
	shell->std_fds[0] = dup(STDIN_FILENO);
	shell->std_fds[1] = dup(STDOUT_FILENO);
}

void	init_missing_environment(t_shell *shell, char **env)
{
	char	*get_path;
	char	path[PATH_MAX];

	get_path = NULL;
	shell->envless = TRUE;
	shell->cmd_paths = NULL;
	shell->color_codes = FALSE;
	get_path = getcwd(get_path, sizeof(path));
	shell->user_name = extract_user(shell);
	env[0] = ft_nm_strjoin("PWD=", get_path);
	env[1] = ft_strdup("SHLVL=1");
	env[2] = ft_strdup("_=/usr/bin/env");
	env[3] = ft_strdup("TERM=xterm-256color");
	env[4] = NULL;
	free(get_path);
	shell->env_head = init_env(env);
}

char	*extract_user(t_shell *shell)
{
	int		fd;
	char	*user;
	char	*trimmed_user;

	fd = open("obj/general_utils/user.txt", O_RDONLY);
	if (fd == -1)
	{
		p_err("%s%s\n", SHELL, UFILE_DELETED);
		trimmed_user = ft_strdup("Having fun trying to break our code?🤨");
		return (trimmed_user);
	}
	user = get_next_line(fd);
	close(fd);
	if (ft_strlen(user) == 0 || user[0] == '\n')
	{
		p_err("%s%s\n", SHELL, UNAME_REMOVED);
		trimmed_user = ft_strdup("Getting trickier huh?🤔");
		return (trimmed_user);
	}
	trimmed_user = ft_strtrim(user, "\n");
	free(user);
	return (trimmed_user);
}
