/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:31:10 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/06 14:05:51 by zstenger         ###   ########.fr       */
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
	curr_dir = get_curr_dir();
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

char	*get_curr_dir(void)
{
	int		i;
	char	*pwd;
	char	**split;

	i = 0;
	pwd = getenv("PWD");
	split = ft_split(pwd, '/');
	while (split[i] != NULL)
		i++;
	pwd = ft_strdup(split[--i]);
	free_char_array(split);
	return (pwd);
}
