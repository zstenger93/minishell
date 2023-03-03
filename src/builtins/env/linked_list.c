/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:02:53 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/03 15:01:40 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_envp	*create_env(char **env)
{
	int			i;
	t_envp		*head;
	t_envp		*new;
	t_envp		*prev;
	char		**split;

	i = 0;
	while (env[i] != NULL)
	{
		split = NULL;
		if (i == 0)
		{
			split = ft_split(env[i], '=');
			head = new_node(env[i], split[0], split[1]);
			split = NULL;
			prev = head;
			free_char_array(split);
			i++;
			// printf("%s=%s\n", head->start, head->content);
		}
		split = ft_split(env[i], '=');
		new = new_node(env[i], split[0], split[1]);
		// printf("%s=%s\n", new->start, new->content);
		add_node_to_list(head, new);
		prev = new;
		free_char_array(split);
		i++;
	}
	prev->next = NULL;
	// printf("%s=%s\n", head->next->start, head->next->content);
	return (head);
}

t_envp	*new_node(char *envp, char *start, char *content)
{
	t_envp	*new_node;

	new_node = malloc(sizeof(t_envp));
	if (new_node == NULL)
		return (NULL);
	new_node->start = start;
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_to_list(t_envp *env, t_envp *new)
{
	if (env == NULL)
		return ;
	while (env->next != NULL)
		env = env->next;
	env->next = new;
	printf("%s=%s\n", env->next->start, env->next->content);
}
