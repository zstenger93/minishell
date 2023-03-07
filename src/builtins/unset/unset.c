/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:31:00 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/07 18:17:21 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_env	*find_env_var(t_env *head, char *var_name)
{
	t_env	*curr;

	curr = head;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->var_name, var_name, ft_strlen(var_name)) == 0
			&& ft_strlen(curr->var_name) == ft_strlen(var_name))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	free_env_var(t_env *env)
{
	free(env->var_name);
	free(env->content);
	free(env);
}

void	delete_env_var(t_env *head, t_env *del)
{
	t_env	*tmp;
	t_env	*curr;

	curr = head;
	while (curr != NULL)
	{
		if (curr->next == del)
		{
			tmp = del->next;
			curr->next = tmp;
			free_env_var(del);
			return ;
		}
		curr = curr->next;
	}
}

void	unset_all_vars(t_shell *shell)
{
	int		i;
	t_env	*env;
	char	**split;

	i = 1;
	split = ft_split(shell->trimmed_prompt, ' ');
	while (split[i] != NULL)
	{
		env = find_env_var(shell->env_head, split[i]);
		if (env != NULL)
		{
			delete_env_var(shell->env_head, env);
			env = NULL;
		}
		i++;
	}
	free_char_array(split);
}

void	unset(t_shell *shell)
{
	if (ft_strncmp(shell->trimmed_prompt, "unset", 5))
		return ;
	else
		unset_all_vars(shell);
}
