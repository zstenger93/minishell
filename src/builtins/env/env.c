/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:54:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 11:12:29 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	env(t_shell *shell)
{
	t_env	*curr;

	if (ft_strlen(shell->trimmed_prompt) > 3)
	{
		p_err("env: %s\n", TMA);
		return ;
	}
	curr = shell->env_head;
	while (curr != NULL)
	{
		if (curr->content == NULL)
			;
		else
			printf("%s=%s\n", curr->var_name, curr->content);
		curr = curr->next;
	}
}

char	*get_full_env(t_env *env)
{
	char	*tmp;
	char	*result;

	tmp = ft_nm_strjoin(env->var_name, "=");
	result = ft_nm_strjoin(tmp, env->content);
	free(tmp);
	return(result);
}

int	get_env_list_size(t_env *head)
{
	t_env	*curr;
	int		i;

	i = 0;
	curr = head;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

char	**env_list_to_char(t_env *env)
{
	char	**result;
	int		size;
	int		i;

	i = 0;
	size = get_env_list_size(env);
	result = malloc(sizeof(char *) * (size + 1));
	result[size] = NULL;
	while (env != NULL && i < size)
	{
		result[i] = get_full_env(env);
		env = env->next;
		i++;
	}
	return (result);
}
