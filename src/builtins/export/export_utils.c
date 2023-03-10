/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 06:59:56 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/08 09:37:19 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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

char	*get_env_content(char *full, char *var_name)
{
	int		i;
	int		j;
	char	*content;
	int		content_len;
	int		var_name_len;

	var_name_len = ft_strlen(var_name);
	if (var_name_len == ft_strlen(full))
		content = NULL;
	else
	{
		content_len = ft_strlen(full) - var_name_len - 1;
		content = malloc(sizeof(char) * (content_len + 1));
		i = var_name_len + 1;
		j = -1;
		while (full[i + ++j] != '\0')
			content[j] = full[i + j];
		content[j] = '\0';
	}
	return (content);
}
