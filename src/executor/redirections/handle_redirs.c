/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:12:52 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/22 15:37:57 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_redirections(t_shell *shell)
{
	t_token	*curr;
	int		fd;

	curr = shell->cmd_tbls->redirs;
	while (curr != NULL)
	{
		if (is_good_redirection(curr) == false)
		{
			shell->exit_code = 258;
			return (-2);
		}
		if (curr->type == HEREDOC && curr->next->type == WORD)
			fd = heredoc(shell, curr->next->content);
		else if (curr->type == OUTPUT && curr->next->type == WORD)
			fd = open_file(OUTPUT, curr->next->content, shell);
		else if (curr->type == APPEND && curr->next->type == WORD)
			fd = open_file(APPEND, curr->next->content, shell);
		else if (curr->type == INPUT && curr->next->type == WORD)
			fd = open_file(INPUT, curr->next->content, shell);
		if (change_stdin_out(curr->type, fd, shell, 0) == FALSE)
			break ;
		set_curr(curr);
	}
	return (fd);
}

bool	change_stdin_out(t_type type, int fd, t_shell *shell, int ret_val)
{
	if (type == HEREDOC)
	{
		ret_val = dup2(fd, STDIN_FILENO);
		close(fd);
		unlink("/tmp/heredoc.XXXXXX");
	}
	if (type == INPUT)
	{
		ret_val = dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else if (type == OUTPUT || type == APPEND)
	{
		ret_val = dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (ret_val == -1)
	{
		shell->exit_code = errno;
		p_err("%s%s\n", SHELL, strerror(errno));
		return (FALSE);
	}
	return (TRUE);
}

bool	is_good_redirection(t_token	*token)
{
	if (is_redirection(token)
		&& token->next != NULL
		&& !is_redirection(token->next))
		return (true);
	return (false);
}

void	set_curr(t_token *curr)
{
	if (curr->next != NULL)
		curr = curr->next->next;
	else
		curr = curr->next;
}