/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:54:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 22:07:06 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
don't try to print content if it's empty
print all the variables in normal mode
don't print term in no env mode
*/
void	env(t_shell *shell, char **args)
{
	t_env	*curr;

	if (args[1] != NULL)
	{
		p_err("env: %s\n", TMA);
		return ;
	}
	curr = shell->env_head;
	if (shell->print == TRUE)
	{
		while (curr != NULL)
		{
			shell->exit_code = 0;
			if (curr->content != NULL && curr->content[0] == ' '
				&& ft_strlen(curr->content) == 1)
				printf("%s=\n", curr->var_name);
			else if (curr->content != NULL && shell->color_codes == TRUE)
				printf("%s=%s\n", curr->var_name, curr->content);
			else if (curr->content != NULL
				&& strcmp_2(curr->var_name, "TERM") == FALSE
				&& shell->color_codes == FALSE)
				printf("%s=%s\n", curr->var_name, curr->content);
			curr = curr->next;
		}
	}
}

char	*get_full_env(t_env *env)
{
	char	*tmp;
	char	*result;

	tmp = ft_nm_strjoin(env->var_name, "=");
	if (env->content != NULL)
	{
		result = ft_nm_strjoin(tmp, env->content);
		free(tmp);
	}
	else
		return (tmp);
	return (result);
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
