/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:08:32 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/03 12:12:01 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**copy_2d_char_array(char **array)
{
	int		i;
	char	**result;

	i = 0;
	if (array == NULL)
		return (NULL);
	while (array[i] != NULL)
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (result == NULL)
		p_err("%s%s\n", SHELL, MALLOC_FAIL);
	i = -1;
	while (array[++i] != NULL)
		result[i] = ft_strdup(array[i]);
	result[i] = NULL;
	return (result);
}

//in case of  no path (path == null) return the correct error
void	clear_and_exit(t_shell *shell, char *cmd_path, t_cmd_tbl *table)
{
	while (table->next != NULL)
		table = table->next;
	if (strcmp_2(table->cmd, "cat") == TRUE
		&& strcmp_2(table->cmd_args[1], "-e") == TRUE && table->next == NULL)
	{
		free(cmd_path);
		free_at_child(shell);
		exit(127);
	}
	else if (cmd_path == NULL && ft_strlen(table->cmd) == 0)
	{
		if (shell->print == TRUE)
			p_err("%s%s: %s\n", SHELL, table->cmd, CMD_NOT_FND);
		free(cmd_path);
		free_at_child(shell);
		exit(126);
	}
	if (shell->print == TRUE)
		p_err("%s%s: %s\n", SHELL, table->cmd, CMD_NOT_FND);
	free(cmd_path);
	free_at_child(shell);
	exit(127);
}

void	waitpid_to_get_exit_status(pid_t pid, t_shell *shell, int *status)
{
	signals_parent();
	shell->print = FALSE;
	waitpid(pid, status, 0);
	shell->exit_code = WEXITSTATUS(*status);
}

void	close_and_dup(t_shell *shell)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	dup2(shell->std_fds[0], STDIN_FILENO);
	dup2(shell->std_fds[1], STDOUT_FILENO);
	if (shell->exit_code != 0)
		shell->cmd_has_been_executed = 0;
}
