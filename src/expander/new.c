/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:27:32 by jergashe          #+#    #+#             */
/*   Updated: 2023/03/27 12:44:46 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_right_cmd(t_cmd_tbl *table,t_shell *shell)
{
	char	*result;
	int		i;

	i = 0;
	if (table->cmd[0] == '$')
	{
		// write(1, "need to expand the cmd\n", 25);
		expander(&table->cmd, shell);
	}
	result = ft_strdup(table->cmd);
	while (result[i] != '\0')
	{
		result[i] = ft_tolower(result[i]);
		i++;
	}
	return (result);
}

void	expand_tokens(t_token *tokens, t_shell *shell)
{
	while (tokens != NULL)
	{
		expander(&tokens->content, shell);
		tokens = tokens->next;
	}
}

void	expand_table(t_cmd_tbl *table, t_shell *shell)
{
	// write(1, "expanding\n", 11);
	expand_tokens(table->args, shell);
	expand_tokens(table->redirs, shell);
}

void	expand_tables(t_cmd_tbl *tables, t_shell *shell)
{
	char	*cmd;

	while (tables != NULL)
	{
		// write(1, "new table\n", 11);
		cmd = NULL;
		cmd = get_right_cmd(tables, shell);
		// printf("RESULT %s\n", tables->cmd);
		if (strcmp_2(cmd, "awk") == FALSE)
			expand_table(tables, shell);
		tables = tables->next;
		free(cmd);
	}
	
}






