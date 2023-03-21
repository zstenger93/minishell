/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:47:49 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 16:47:52 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	redir_check(char *str)
{
	int	i;

	i = 0;
	while (ft_strlen(str) > 2 && i != ft_strlen(str) - 2)
	{
		if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>')
			return (syntax_error(str[i]), TRUE);
		i++;
	}
	i = 0;
	while (ft_strlen(str) > 2 && i != ft_strlen(str) - 2)
	{
		if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
			return (syntax_error(str[i]), TRUE);
		i++;
	}
	return (FALSE);
}

bool	has_wrong_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '|')
		{
			if (redir_after(str, i))
				return (true);
			if (redir_before(str, i))
				return (true);
		}
	}
	return (false);
}

// have redirection after pipe but no escape before pipe -> WRONG
// have redirection after pipe and escape before pipe -> WRONG
bool	redir_after(char *str, int i)
{
	if (ft_pf_strchr(REDIRECTIONS, str[i + 1]) && str[i - 1] != 92)
		return (true);
	if (ft_pf_strchr(REDIRECTIONS, str[i + 1]) && str[i - 1] == 92)
		if (nb_esc_chars(str, i) % 2 == 0)
			return (true);
	return (false);
}

// redirection before pipe but no escape before redirection -> WRONG
// redirection before pipe and not escaped escape before redirection -> WRONG
bool	redir_before(char *str, int i)
{
	if (ft_pf_strchr(REDIRECTIONS, str[i - 1]) && str[i - 2] != 92)
		return (true);
	if (ft_pf_strchr(REDIRECTIONS, str[i - 1]) && str[i - 2] == 92)
		if (nb_esc_chars(str, i - 1) % 2 == 0)
			return (true);
	return (false);
}

bool	special_char_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (is_special_char(str[i]))
			return (syntax_error(str[i]), TRUE);
	return (FALSE);
}
