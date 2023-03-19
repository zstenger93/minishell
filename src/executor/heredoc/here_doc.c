/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:47:23 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/19 00:20:48 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	heredoc(t_shell *shell, char *delimeter)
{
	char	*input_line;
	char	*tmp;

	set_heredoc_to_null(shell);
	write(1, "> ", 2);
	while (1)
	{
		input_line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(input_line, delimeter, ft_strlen(delimeter)) == 0)
		{
			free(input_line);
			break ;
		}
		if (shell->heredoc == NULL)
			shell->heredoc = ft_strdup(input_line);
		else
		{
			tmp = ft_nm_strjoin(shell->heredoc, input_line);
			free(shell->heredoc);
			shell->heredoc = tmp;
		}
		free(input_line);
		write(1, "> ", 2);
	}
	printf("%s", shell->heredoc);
}

void	set_heredoc_to_null(t_shell *shell)
{
	if (shell->heredoc != NULL)
	{
		free(shell->heredoc);
		shell->heredoc = NULL;
	}
}
