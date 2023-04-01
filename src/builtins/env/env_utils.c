/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:02:53 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/01 08:09:51 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// str is "USER=jergashe" || "a=" || "c"
t_env	*init_env_node(char *str)
{
	char	**split;
	t_env	*env_node;

	env_node = malloc(sizeof(t_env));
	if (env_node == NULL)
		p_err("%s%s\n", SHELL, MALLOC_FAIL);
	split = ft_split(str, '=');
	env_node->var_name = ft_strdup(split[0]);
	env_node->content = get_env_content(str, split[0]);
	env_node->next = NULL;
	free_char_array(split);
	return (env_node);
}

void	add_back_env_node(t_env	*head, t_env *new)
{
	t_env	*curr;

	curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

// env is from main(argc, argv, env)
t_env	*init_env(char **env)
{
	int		i;
	t_env	*head;

	i = 0;
	head = init_env_node(env[i++]);
	while (env[i] != NULL)
		add_back_env_node(head, init_env_node(env[i++]));
	return (head);
}

void	print_env_vars(t_env *head)
{
	t_env	*curr;

	curr = head;
	while (curr != NULL)
	{
		printf("%s=%s\n", curr->var_name, curr->content);
		curr = curr->next;
	}
}

char	*get_path(char **env)
{
	int	index;

	index = 0;
	while (env[index] != NULL)
	{
		if (ft_strncmp(env[index], "PATH=", 5) == 0)
			return (env[index] + 5);
		index++;
	}
	return (NULL);
}
