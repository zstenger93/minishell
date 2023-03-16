/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:39:58 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/16 12:28:28 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//need to check on the coversion at $? with itoa, its leaking
char	*expand_dollars(char *dollar_to_expand, t_shell *shell)
{
	char	*variable;
	char	*expanded_dollar;

	variable = expand(dollar_to_expand, shell);
	if (ft_strlen(variable) == 0)
		return (variable);
	expanded_dollar = copy_variable(variable);
	if (dollar_to_expand[1] == '?')
		free(variable);
	return (expanded_dollar);
}

char	*expand(char *dollar_to_expand, t_shell *shell)
{
	int		i;
	char	*trimmed_dollar;
	char	*expanded_dollar;

	i = 0;
	trimmed_dollar = ft_strtrim(dollar_to_expand, "$");
	if (trimmed_dollar[0] == '?')
		expanded_dollar = replace_variable(trimmed_dollar, shell);
	if (trimmed_dollar[0] == '(')
	{
		while (trimmed_dollar[i] != '\0')
			i++;
		if (trimmed_dollar[i - 1] == ')')
			expanded_dollar = replace_variable(trimmed_dollar, shell);
		else
			expanded_dollar = ft_strdup("");
	}
	else
		expanded_dollar = replace_variable(trimmed_dollar, shell);
	free(trimmed_dollar);
	return (expanded_dollar);
}

//add extra trim after taking off brackets
char	*replace_variable(char *variable, t_shell *shell)
{
	t_env	*curr;
	char	*trimmed_variable;

	if (variable[0] == '?')
		return (ft_itoa(shell->exit_code));
	trimmed_variable = ft_strtrim(variable, "( )");
	if (variable[0] == '(')
	{
		curr = find_env_var(shell->env_head, trimmed_variable);
		free(trimmed_variable);
		if (curr == NULL)
			return (variable_doesnt_exist());
		return (curr->content);
	}
	else if (trimmed_variable[0] != '(' || trimmed_variable[0] != ' '
		|| trimmed_variable)
	{
		curr = find_env_var(shell->env_head, trimmed_variable);
		free(trimmed_variable);
		if (curr == NULL)
			return (variable_doesnt_exist());
		return (curr->content);
	}
	free(trimmed_variable);
	return (variable_doesnt_exist());
}

char	*variable_doesnt_exist(void)
{
	char	*space;

	space = ft_strdup("");
	return (space);
}

char	*copy_variable(char *content)
{
	int		i;
	int		content_len;
	char	*var_content;

	i = -1;
	content_len = ft_strlen(content) + 1;
	var_content = malloc(sizeof(char) * content_len);
	while (content[++i] != '\0')
		var_content[i] = content[i];
	var_content[i] = '\0';
	return (var_content);
}
