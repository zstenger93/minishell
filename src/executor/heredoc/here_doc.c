/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:47:23 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/25 09:09:34 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	heredoc(t_shell *shell, char *delimeter)
{
	int		fd;
	char	*input_line;

	// close(STDIN_FILENO);
	dup2(shell->std_fds[0], STDIN_FILENO);
	// dup2(shell->std_fds[1], STDOUT_FILENO);
	fd = open("/tmp/heredoc.XXXXXX", O_RDWR | O_CREAT | O_EXCL, 0600);
	if (fd == -1)
		return (-1);
	write(2, "> ", 2);
	while (1)
	{
		input_line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(input_line, delimeter, ft_strlen(delimeter)) == 0)
		{
			free(input_line);
			break ;
		}
		expander(&input_line, shell);
		write(fd, input_line, ft_strlen(input_line));
		free(input_line);
		write(2, "> ", 2);
	}
	close(fd);
	fd = open("/tmp/heredoc.XXXXXX", O_RDONLY);
	return (fd);
}

void	set_heredoc_to_null(t_shell *shell)
{
	if (shell->heredoc != NULL)
	{
		free(shell->heredoc);
		shell->heredoc = NULL;
	}
}
