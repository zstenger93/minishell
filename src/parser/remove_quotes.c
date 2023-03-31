/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:44:49 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 18:37:09 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rm_quotes_tables(t_cmd_tbl *tables, t_shell *shell)
{
	char	*tmp;

	while (tables != NULL)
	{
		if (tables->cmd != NULL)
		{
			tmp = rm_quotes(tables->cmd);
			free(tables->cmd);
			tables->cmd = tmp;
			cmd_to_lover_case(tables);
		}
		if (strcmp_2(tables->cmd, "echo") == FALSE
			&& strcmp_2(tables->cmd, "export") == FALSE)
			rm_quotes_table(tables, shell);
		tables = tables->next;
	}
}

char	*rm_quotes(char *str)
{
	char	*result;
	int		i;

	if (str[0] == SQUOTE || str[0] == DQUOTE)
	{
		result = ft_strdup2(str, 1, ft_strlen(str) - 1);
		return (result);
	}
	return (ft_strdup(str));
}

void	rm_quotes_tokenss(t_token *tokens, t_shell *shell, t_token *args)
{
	char	*tmp;

	while (tokens != NULL)
	{
		if (tokens->type == HEREDOC)
		{
			tokens = tokens->next;
			if (tokens != NULL)
				tokens = tokens->next;
			if (tokens == NULL)
				return ;
		}
		tmp = rm_quotes(tokens->content);
		free(tokens->content);
		tokens->content = tmp;
		tokens = tokens->next;
	}
}

void	rm_quotes_table(t_cmd_tbl *table, t_shell *shell)
{
	rm_quotes_tokens(table->args, shell);
	rm_quotes_tokenss(table->redirs, shell, table->args);
}

void	rm_quotes_tokens(t_token *tokens, t_shell *shell)
{
	char	*tmp;

	while (tokens != NULL)
	{
		if (tokens->type == HEREDOC)
		{
			tokens = tokens->next;
			if (tokens != NULL)
				tokens = tokens->next;
			if (tokens == NULL)
				return ;
		}
		tmp = rm_quotes(tokens->content);
		free(tokens->content);
		tokens->content = tmp;
		tokens = tokens->next;
	}
}
