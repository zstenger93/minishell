/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:44:20 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/22 19:28:45 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// set exit code at return
int	open_file(t_type type, char *file_name, t_shell *shell)
{
	int		fd;
	char	*pwd;

	if (type == INPUT)
		fd = open(file_name, O_RDONLY);
	else if (type == OUTPUT)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, GIVE_PERM_WTH_RW);
	else if (type == APPEND)
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, GIVE_PERM_WTH_RW);
	if (fd == -1)
	{
		p_err("%s%s: %s\n", SHELL, file_name, strerror(ENOENT));
		shell->exit_code = 1;
	}
	return (fd);
}
