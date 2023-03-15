/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:02:56 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/15 08:05:44 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_here_doc(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i] != ' ')
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			if (i == 0)
				return (i);
			if (nb_esc_chars(str, i) % 2 == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}

int is_append(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i] != ' ')
	{
		if (str[i] == '>' && str[i + 1] == '>')
		{
			if (i == 0)
				return (i);
			if (nb_esc_chars(str, i) % 2 == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}

int	is_output(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i] != ' ')
	{
		if (str[i] == '>')
		{
			if (i == 0)
				return (i);
			if (nb_esc_chars(str, i) % 2 == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}

int	is_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str[i] != ' ')
	{
		if (str[i] == '<')
		{
			if (i == 0)
				return (i);
			if (nb_esc_chars(str, i) % 2 == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}

t_io_here	get_io_here_type(char *str)
{
	t_io_here	result;
	int			i;

	if (is_here_doc(str) >= 0)
	{
		i = is_here_doc(str);
		result	= HERE_DOC;
	}
	else if (is_append(str) >= 0)
	{
		i = is_append(str);
		result = APPEND;
	}
	else if (is_input(str) >= 0)
	{
		i = is_input(str);
		result = INPUT;
	}
	else if (is_output(str) >= 0)
	{
		i = is_output(str);
		result = OUTPUT;
	}
	return (WORD);
}

bool	has_cmd(char *str)
{
	if (ft_pf_strchr(REDIRECTIONS, str[0]) == NULL)
		return (true);
	return (false);
}

char	*extract_cmd_name(char *str, int start)
{
	int		i;
	char	*result;

	i = start;
	while (str[i] != '\0' || ft_pf_strchr(SPACES, str[i])
		|| ft_pf_strchr(REDIRECTIONS, str[i]))
		i++;
	result = ft_strdup2(str, start, i + 1);
	return (result);
}

char	*get_cmd(char *str)
{
	int	i;

	if (get_io_here_type(str) == WORD)
		return (get_cmd_name(str, 0));
	if (has_cmd(str) == true)
		return (get_cmd_name(str, 0));
	return (NULL);
}
