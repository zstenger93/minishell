/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:31:10 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/12 13:10:23 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//make the color of the arrow change depending if the prev command exit code is
// 0 or something else
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
	if (shell->exit_code == 0)
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
