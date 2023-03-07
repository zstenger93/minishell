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
	int		i;
	char	**split_var;
	char	**split_prompt;

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

void	print_export(t_shell *shell)
{
	t_env	*curr;

	curr = shell->env_head;
	while (curr != NULL)
	{
		if (curr->content == NULL)
			printf("declare -x %s\n", curr->var_name);
		else
			printf("declare -x %s=\"%s\"\n", curr->var_name, curr->content);
		curr = curr->next;
	}
}
