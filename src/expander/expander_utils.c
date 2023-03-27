/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:40:39 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/27 10:12:23 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	has_dollar(char *str, t_shell *shell)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[0] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
			return (TRUE);
		else if (str[i] == '$' && str[i + 1] == '\0')
			break ;
		else if ((str[i] == '$' && str[i - 1] == 92)
			|| (str[i] == '$' && dont_expand(str, i) == TRUE))
			i++;
		else if (str[i] == '$' && ft_pf_strchr(SPACES, str[i + 1]) != NULL)
		{
			shell->cmd_has_been_executed = FALSE;
			return (syntax_error(str[i]), FALSE);
		}
		else if (str[i] == '$'
			&& ft_pf_strchr(SPACES, str[i + 1]) == NULL)
			return (TRUE);
	}
	return (FALSE);
}

void	copy_dollar_from_string(char **dst, char **s, int index)
{
	char	delimeter;
	int		i;
	int		doll;

	if (s[0][index + 1] == '?')
		dst[0] = ft_strdup2(s[0], index, index + 2);
	else
	{
		i = index;
		doll = index + 1;
		delimeter = ' ';
		if (s[0][index + 1] == '(')
			delimeter = ')';
		if (index > 0 && s[0][index - 1] == '\'' )
			delimeter = '\'';
		if (index > 0 && s[0][index - 1] == '\"' )
			delimeter = '\"';
		while (s[0][i] != '\0' && s[0][i] != delimeter
			&& s[0][doll] >= 40 && 122 >= s[0][doll])
		{
			i++;
			doll++;
		}
		dst[0] = ft_strdup2(s[0], index, i + 1);
	}
}

void	extract_dollar(char **s, t_shell *sh, char **bef_doll, char **rest)
{
	int		i;
	char	**doll;
	char	*val;

	doll = malloc(sizeof(char *));
	i = -1;
	while (s[0][++i] != '\0')
	{
		if (s[0][i] == '$' && s[0][i - 1] != 92 && dont_expand(s[0], i) != TRUE)
		{
			bef_doll[0] = ft_strdup2(s[0], 0, i);
			copy_dollar_from_string(doll, s, i);
			val = expand_dollars(doll[0], sh);
			rest[0] = ft_strdup2(s[0], i + ft_strlen(*doll), ft_strlen(s[0]));
			free(doll[0]);
			*doll = ft_strjoin(bef_doll[0], val);
			bef_doll[0] = ft_nm_strjoin(doll[0], rest[0]);
			free(doll[0]);
			free(doll);
			free(s[0]);
			*s = *bef_doll;
			break ;
		}
	}
}

bool	expander(char **str, t_shell *shell)
{
	char	**before_dollar;
	char	**after_dollar;

	if (str[0][0] == '$' && shell->should_expand == FALSE)
		return (TRUE);
	while (has_dollar(*str, shell) == TRUE)
	{
		before_dollar = malloc(sizeof(char *));
		after_dollar = malloc(sizeof(char *));
		extract_dollar(&*str, shell, before_dollar, after_dollar);
		free(after_dollar[0]);
		free(before_dollar);
		free(after_dollar);
	}
	return (TRUE);
}

char	*copy_variable(char *content)
{
	int		i;
	int		content_len;
	char	*var_content;

	i = -1;
	content_len = ft_strlen(content) + 1;
	var_content = malloc(sizeof(char) * content_len);
	while (content[++i] != '\0')
		var_content[i] = content[i];
	var_content[i] = '\0';
	return (var_content);
}
