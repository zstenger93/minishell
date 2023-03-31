/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:39:58 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 10:46:42 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*expand_dollars(char *doll_to_exp, t_shell *shell)
{
	char	*variable;
	char	*expanded_dollar;

	if (doll_to_exp[1] == '?')
		expanded_dollar = return_exit_status(shell);
	else
	{
		variable = type_to_expand(doll_to_exp, shell);
		if (variable == NULL || *variable == '\0')
			return (variable);
		expanded_dollar = copy_variable(variable);
		if (expanded_dollar[0] == ' ' && expanded_dollar[1] == '\0')
		{
			free(expanded_dollar);
			expanded_dollar = variable_doesnt_exist();
		}
	}
	return (expanded_dollar);
}

char	*return_exit_status(t_shell *shell)
{
	char	*exit_status;

	exit_status = ft_itoa(shell->exit_code);
	return (exit_status);
}

char	*type_to_expand(char *dollar_to_expand, t_shell *shell)
{
	int		i;
	char	*trimmed_dollar;
	char	*expanded_dollar;

	i = 0;
	trimmed_dollar = ft_strtrim(dollar_to_expand, "$");
	if (trimmed_dollar[0] == '(')
	{
		while (trimmed_dollar[i] != '\0')
			i++;
		if (trimmed_dollar[i - 1] == ')')
			expanded_dollar = replace_variable(trimmed_dollar, shell);
		else
			expanded_dollar = variable_doesnt_exist();
	}
	else
		expanded_dollar = replace_variable(trimmed_dollar, shell);
	free(trimmed_dollar);
	return (expanded_dollar);
}

char	*replace_variable(char *variable, t_shell *shell)
{
	t_env	*curr;
	char	*trimmed_variable;

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

	space = malloc(sizeof(char));
	space[0] = '\0';
	return (space);
}
