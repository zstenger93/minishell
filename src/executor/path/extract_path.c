/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:34:21 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 13:43:20 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*extract_path(t_shell *shell, char *command)
{
	int		i;
	char	*path;
	char	*slash_cmd;

	if (ft_strlen(command) == 0)
		return (NULL);
	if (shell->cmd_paths == NULL)
		child_exit(shell);
	i = 0;
	while (shell->cmd_paths[i] != NULL)
	{
		slash_cmd = ft_nm_strjoin("/", command);
		path = ft_nm_strjoin(shell->cmd_paths[i], slash_cmd);
		free(slash_cmd);
		if (path == NULL)
		{
			free(path);
			return (invalid_command(shell, command), NULL);
		}
		else if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	invalid_command(t_shell *shell, char *command)
{
	if (shell->print == TRUE)
		p_err("%s%s: %s\n", SHELL, command, INVALID_CMD);
	shell->exit_code = 127;
}
