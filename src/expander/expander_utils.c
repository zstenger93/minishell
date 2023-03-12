/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:40:39 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/12 17:50:23 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	has_dollar(char *str, t_shell *shell)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '$' && str[i - 1] == 92)
			i++;
		else if (str[i] == '$' && ft_pf_strchr(SPACES, str[i + 1]) != NULL)
		{
			syntax_error(str[i]);
			shell->cmd_has_been_executed = FALSE;
		}
		else if (str[i] == '$'
			&& ft_pf_strchr(SPACES, str[i + 1]) == NULL)
			return (TRUE);
	}
	return (FALSE);
}

void	get_dollar(char **dst, char **s, int index)
{
	char	delimeter;
	int		i;

	i = index;
	delimeter = ' ';
	if (s[0][index + 1] == '(')
		delimeter = ')';
	while (s[0][i] != delimeter)
		i++;
	if (delimeter == ' ')
		i--;
	dst[0] = ft_strdup2(s[0], index, i + 1);
}

void	extract_dollar(char **s, t_shell *shell) //  echo $(PWD ) dasdasdasd  
{
	int		i;
	char	**before_dollar;
	char	**after_dollar;
	char	**dollar_to_expand;
	char	*dollar_expanded;

	after_dollar = malloc(sizeof(char *) * 1);
	before_dollar = malloc(sizeof(char *) * 1);
	dollar_to_expand = malloc(sizeof(char *) * 1);
	i = 0;
	while (s[0][i] != '\0')
	{
		if (s[0][i] == 36 && (i > 0 && s[0][i - 1] != 92))
		{
			before_dollar[0] = ft_strdup2(s[0], 0, i); // "echo "
			get_dollar(dollar_to_expand, s, i); // $(PWD )
			dollar_expanded = expand_dollars(dollar_to_expand[0], shell); // expand PWD to "PATH"
			after_dollar[0] = ft_strdup2(s[0], i + ft_strlen(*dollar_to_expand), ft_strlen(s[0])); // " dasdasdasd "
			
			free(dollar_to_expand[0]);
			*dollar_to_expand = ft_nm_strjoin(before_dollar[0], dollar_expanded); // "echo PATH"
			free(before_dollar[0]);
			free(dollar_expanded);
			before_dollar[0] = ft_nm_strjoin(dollar_to_expand[0], after_dollar[0]); // "echo PATH dasdasdasd"
			
			free(after_dollar[0]);
			free(dollar_to_expand[0]);
			free(after_dollar);
			free(dollar_to_expand);
			free(s[0]);
			*s = *before_dollar;
			free(before_dollar);
			break ;
		}
		i++;
	}
}

void	expander(char **str, t_shell *shell)
{
	if (str[0][0] == '$')
	{
		shell->cmd_has_been_executed = FALSE;
		syntax_error(str[0][0]);
		return ;
	}
	while (has_dollar(*str, shell) == TRUE)
		extract_dollar(str, shell);
}

// $(PWD ) dasdasdasd  | cat $USER | sdasd $( HOME )
