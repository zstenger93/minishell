/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:02:56 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/14 16:11:23 by zstenger         ###   ########.fr       */
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
	if (is_here_doc(str) >= 0)
		return (HEREDOC);
	if (is_append(str) >= 0)
		return (APPEND);
	if (is_input(str) >= 0)
		return (INPUT);
	if (is_output(str) >= 0)
		return (OUTPUT);
	return (WORD);
}

char	*get_cmd(char *str)
{
	int	i;

	if (get_io_here_type(str) == WORD)
	{
		
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (get_io_here_type(str) == HEREDOC)
		{
			
		}
	}
	
}
