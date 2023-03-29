/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:47:23 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/29 18:25:21 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_heredocs(t_cmd_tbl *cmd_tbl, t_shell *shell)
{
	while (cmd_tbl != NULL)
	{
		if (cmd_tbl_has_heredoc(cmd_tbl) == true)
		{
			execute_heredocs(cmd_tbl, shell);
		}
		cmd_tbl = cmd_tbl->next;
	}
}

bool	cmd_tbl_has_heredoc(t_cmd_tbl *cmd_tbl)
{
	t_token	*token;

	if (cmd_tbl == NULL)
		return (false);
	token = cmd_tbl->redirs;
	while (token != NULL)
	{
		if (token->type == HEREDOC)
			return (true);
		token = token->next;
	}
	return (false);
}

void	execute_heredocs(t_cmd_tbl *cmd_tbl, t_shell *shell)
{
	t_token	*tk;
	char	*tmp;

	tk = cmd_tbl->redirs;
	while (tk != NULL)
	{
		if (tk->type == HEREDOC)
		{
			tmp = stop_word(tk->next->content, shell);
			free(tk->next->content);
			tk->next->content = tmp;
			cmd_tbl->heredoc_name = heredoc(cmd_tbl, tk->next->content, shell);
		}
		tk = tk->next;
	}
}

char	*heredoc(t_cmd_tbl *cmd_tbl, char *stop_word, t_shell *shell)
{
	int		fd;
	char	*input_line;

	cmd_tbl->heredoc_name = filename(cmd_tbl);
	fd = open(cmd_tbl->heredoc_name, O_RDWR | O_CREAT | O_EXCL, 0600);
	if (fd == -1)
		p_err("%s%s\n", SHELL, strerror(errno));
	write(0, "> ", 2);
	while (1)
	{
		input_line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(input_line, stop_word, ft_strlen(stop_word)) == 0
			&& ((ft_strlen(input_line) - 1) == ft_strlen(stop_word)))
		{
			free(input_line);
			break ;
		}
		shell->should_expand = TRUE;
		if (shell->expand_heredoc == TRUE)
			expander(&input_line, shell);
		write(fd, input_line, ft_strlen(input_line));
		free(input_line);
		write(0, "> ", 2);
	}
	shell->should_expand = FALSE;
	return (close(fd), cmd_tbl->heredoc_name);
}

char	*filename(t_cmd_tbl *table)
{
	char	*tmp;
	char	*tmp1;
	char	*i;

	if (table->heredoc_name != NULL)
	{
		unlink(table->heredoc_name);
		return (table->heredoc_name);
	}
	i = ft_itoa(table->index);
	tmp = ft_nm_strjoin(TMP_S, i);
	free(i);
	tmp1 = ft_nm_strjoin(tmp, TMP_E);
	free(tmp);
	unlink(tmp1);
	return (tmp1);
}
