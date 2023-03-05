/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:54:54 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/05 14:55:33 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**copy_env(char **env)
{
	size_t i;
	int len;
	char **copy;
	
	i = 0;
	len = 0;
	while (env[len] != NULL)
		len++;
	copy = ft_calloc(sizeof(char *), len + 1);
	if (!copy)
		return (NULL);
	while (env[i] != NULL)
	{
		copy[i] = ft_strdup(env[i]);
		if (copy[i] == NULL)
		{
			free_char_array(copy);
			return(copy);
		}
		i++;
	}
	return (copy);
}

void	print_env(char **env_path, char *line)
{
	int		i;
	char	**split;

	i = 0;
	if (ft_strncmp(line, "env", 3) == 0)
	{
		while (env_path[i] != NULL)
		{
			printf("%s\n", env_path[i]);
			i++;
		}
	}
	else if (ft_strncmp(line, "export", 6) == 0)
	{
		while (env_path[i] != NULL)
		{
			split = ft_split(env_path[i], '=');
			printf("declare -x %s=\"%s\"\n", split[0], split[1]);
			free_char_array(split);
			i++;
		}
	}
}

char	*get_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
