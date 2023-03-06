/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:27:28 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/06 16:04:00 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	export_new_env(t_env *head, t_env *new)
{
	t_env	*curr;
	t_env	*tmp;

	curr = head;
	while (curr->next->next != NULL)
		curr = curr->next;
	tmp = curr->next;
	curr->next = new;
	new->next = tmp;
}

//skip whitespaces & tabs
//change the export print
void	export(t_shell *shell)
{
	t_env	*new;
	char	*var;

	if (ft_strncmp(shell->prompt, "export", 6) == 0
		&& ft_strlen(shell->prompt) == 6)
		print_env_vars(shell->env_head);
	else if (ft_strncmp(shell->prompt, "export ", 6) == 0
		&& ft_pf_strchr(shell->prompt, '=') == NULL)
		return ;
	else if (ft_strncmp(shell->prompt, "export ", 6) == 0
		&& ft_pf_strchr(shell->prompt, '=') != NULL)
	{
		var = get_variable(shell->prompt);
		new = init_env_node(var);
		free(var);
		export_new_env(shell->env_head, new);
	}
}

char	*get_variable(char *prompt)
{
	char	*trimmed;
	char	**split;
	char	*variable;
	int		i;

	i = 0;
	trimmed = ft_strtrim(prompt, "\t ");
	split = ft_split(trimmed, ' ');
	variable = ft_strdup(split[1]);
	free(trimmed);
	free_char_array(split);
	return (variable);
}
