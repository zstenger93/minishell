/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:54:11 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 18:27:38 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*stop_word(char *str, t_shell *shell)
{
	int		i;
	char	*trim;
	char	*result;

	i = 0;
	shell->expand_heredoc = TRUE;
	while (str[i] != '\0')
	{
		if (str[i] == SQUOTE || str[i] == DQUOTE)
			shell->expand_heredoc = FALSE;
		i++;
	}
	trim = malloc(sizeof(char) * 3);
	trim[0] = SQUOTE;
	trim[1] = DQUOTE;
	trim[2] = '\0';
	result = ft_strtrim(str, trim);
	free(trim);
	return (result);
}
