/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:17:42 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 08:25:40 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_shell(t_shell *shell, char **env)
{
	t_token	token;

	if (getenv("USER") == NULL)
		init_missing_environment(shell, env);
	else
		shell->env_head = init_env(env);
	shell->exit_code = 0;
	shell->echo_flag = 0;
	shell->heredoc = NULL;
	shell->prev_prompt = NULL;
	shell->trimmed_prompt = NULL;
	shell->terminal_prompt = NULL;
	shell->user_name = getenv("USER");
	shell->cmd_has_been_executed = TRUE;
	shell->cmd_paths = ft_split(get_path(env), ':');
}

//segfaults in iterm except if the file doesnt exist
//check for leaks and to copy directly to our env or not
void	init_missing_environment(t_shell *shell, char **env)
{
	char	*user;
	char	*get_path;
	char	*username;
	char	*home;
	char	path[PATH_MAX];

	get_path = NULL;
	get_path = getcwd(get_path, sizeof(path));
	user = extract_user(shell);
	home = ft_nm_strjoin("HOME=/Users/", user);
	username = ft_nm_strjoin("USER=", user);
	env[0] = ft_nm_strjoin("PWD=", get_path);
	env[1] = ft_strdup(home);
	env[2] = ft_strdup("SHLVL=1");
	env[3] = ft_strdup("_=/usr/bin/env");
	env[4] = ft_strdup(username);
	env[5] = NULL;
	free(home);
	free(user);
	free(username);
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
	dup2(fd, 666);
	user = get_next_line(666);
	close(fd);
	if (ft_strlen(user) == 0 || user[0] == '\n')
	{
		p_err("%s%s\n", SHELL, UNAME_REMOVED);
		trimmed_user = ft_strdup("Getting trickier huh?🤔");
		return (trimmed_user);
	}
	trimmed_user = ft_strtrim(user, "\n");
	free(user);
	close(666);
	return (trimmed_user);
}
