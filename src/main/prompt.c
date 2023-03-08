/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:31:10 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/08 19:59:36 by zstenger         ###   ########.fr       */
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
	username = ft_nm_strjoin(ARROW_SIGN, shell->user_name);
	directory = ft_nm_strjoin(SPACE_SIGN, curr_dir);
	half = ft_nm_strjoin(username, directory);
	full = ft_nm_strjoin(half, X_SIGN);
	free(directory);
	free(username);
	free(curr_dir);
	free(half);
	shell->terminal_prompt = full;
}

char	*get_curr_dir(t_shell *shell)
{
	int		i;
	t_env	*pwd;
	char	**split;
	char	*directory;

	i = 0;
	pwd = find_env_var(shell->env_head, "PWD");
	split = ft_split(pwd->content, '/');
	while (split[i] != NULL)
		i++;
	directory = ft_strdup(split[--i]);
	free_char_array(split);
	return (directory);
}
