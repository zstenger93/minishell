/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:27:28 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/07 18:19:14 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//check if the second trim is needed or not
void	export(t_shell *shell)
{
	if (ft_strncmp(shell->trimmed_prompt, "export", 6) == 0
		&& ft_strlen(shell->trimmed_prompt) == 6)
		print_export(shell);
	else if (ft_strncmp(shell->trimmed_prompt, "export ", 7) == 0
		&& ft_pf_strchr(shell->trimmed_prompt, '=') == NULL)
		return ;
	else if (ft_strncmp(shell->trimmed_prompt, "export ", 7) == 0
		&& ft_pf_strchr(shell->trimmed_prompt, '=') != NULL)
		export_new_variables(shell);
}

void	export_new_variables(t_shell *shell)
{
	char	**split_prompt;
	int		i;
	char	**split_var;

	i = 1;
	split_prompt = ft_split(shell->trimmed_prompt, ' ');
	while (split_prompt[i] != NULL)
	{
		split_var = ft_split(split_prompt[i], '=');
		if (find_env_var(shell->env_head, split_var[0]) == NULL)
			add_new_variable(shell, split_prompt[i]);
		else
			replace_var_content(shell, split_prompt[i], split_var[0]);
		free_char_array(split_var);
		i++;
	}
	free_char_array(split_prompt);
}

void	replace_var_content(t_shell *shell, char *str, char *var)
{
	t_env	*curr;

	curr = shell->env_head;
	while (curr != NULL)
	{
		if (ft_strcmp(curr->var_name, var) == 1)
		{
			free(curr->content);
			curr->content = get_env_content(str, var);
		}
		curr = curr->next;
	}
}

void	add_new_variable(t_shell *shell, char *str)
{
	t_env	*new;

	new = init_env_node(str);
	add_back_env_node(shell->env_head, new);
}

int	count_equal_sign(t_shell *shell)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (shell->trimmed_prompt[i] != '\0')
	{
		if (shell->trimmed_prompt[i] == '=')
			count++;
		i++;
	}
	return (count);
}

char	*get_variable(char *prompt)
{
	char	**split;
	char	*variable;
	int		i;

	i = 0;
	split = ft_split(prompt, ' ');
	variable = ft_strdup(split[1]);
	free_char_array(split);
	return (variable);
}

void	print_export(t_shell *shell)
{
	t_env	*curr;

	curr = shell->env_head;
	while (curr != NULL)
	{
		if (ft_strlen(curr->content) == 0)
			printf("declare -x %s\n", curr->var_name);
		else
			printf("declare -x %s=\"%s\"\n", curr->var_name, curr->content);
		curr = curr->next;
	}
}

char	*get_env_content(char *full, char *var_name)
{
	int		content_len;
	int		var_name_len;
	char	*content;
	int		i;
	int		j;

	var_name_len = ft_strlen(var_name);
	content_len = ft_strlen(full) - var_name_len - 1;
	content = malloc(sizeof(char) * (content_len + 1));
	i = var_name_len + 1;
	j = -1;
	while (full[i + ++j] != '\0')
		content[j] = full[i + j];
	content[j] = '\0';
	return (content);
}
