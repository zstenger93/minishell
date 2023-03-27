/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:31:10 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/27 19:30:44 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	terminal_prompt(t_shell *shell)
{
	char	*half;
	char	*full;
	char	*username;
	char	*curr_dir;
	char	*directory;

	if (shell->terminal_prompt != NULL)
		free(shell->terminal_prompt);
	curr_dir = get_curr_dir(shell);
	if (shell->cmd_has_been_executed == TRUE)
		username = ft_nm_strjoin(G_ARROW_SIGN, shell->user_name);
	else
		username = ft_nm_strjoin(R_ARROW_SIGN, shell->user_name);
	directory = ft_nm_strjoin(SPACE_SIGN, curr_dir);
	half = ft_nm_strjoin(username, directory);
	full = ft_nm_strjoin(half, X_SIGN);
	free(directory);
	free(username);
	free(curr_dir);
	free(half);
	shell->terminal_prompt = full;
	shell->cmd_has_been_executed = TRUE;
}

char	*get_curr_dir(t_shell *shell)
{
	int		i;
	t_env	*pwd;
	char	**split;
	char	*directory;

	i = 0;
	pwd = find_env_var(shell->env_head, "PWD");
	if (ft_strcmp(pwd->content, "/") == TRUE)
		directory = ft_strdup("/");
	else
	{
		split = ft_split(pwd->content, '/');
		while (split[i] != NULL)
			i++;
		directory = ft_strdup(split[--i]);
		free_char_array(split);
	}
	return (directory);
}
