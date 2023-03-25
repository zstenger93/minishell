/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:02:03 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/25 20:04:26 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//does bash write exit after exit?
void	exit_shell(t_shell *shell, char *cmd, char **args)
{
	// if (is_wrong_command(shell->trimmed_prompt, ' ') > 2)
	// 	return ;
	if (ft_strcmp(cmd, "exit") == TRUE && args[1] == NULL)
	{
		free_at_exit(shell);
		exit(shell->exit_code);
	}
	else if (ft_strcmp(cmd, "exit") == TRUE && args[2] == NULL)
		exit_code(shell, args);
	else
	{
		p_err("exit: %s\n", TMA);
		return ;
	}
}

void	exit_code(t_shell *shell, char **args)
{
	int		i;
	int		len;
	int		code;
	char	*code_str;

	i = 5;
	len = ft_strlen(args[1]);
	code_str = (char *)malloc(sizeof(char) * (len + 1));
	if (code_str == NULL)
	{
		free_at_exit(shell);
		exit(EXIT_FAILURE);
	}
	strcpy(code_str, args[1]);
	code = ft_atoi(code_str);
	free_at_exit(shell);
	free(code_str);
	exit(code);
}

int	is_wrong_command(char *s, char c)
{
	int	boo;
	int	count;
	int	index;

	boo = 0;
	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			boo = 0;
		else if (s[index] != c && boo == 0)
		{
			count++;
			boo = -1;
		}
		index++;
	}
	if (count > 2)
		p_err("exit: %s", TMA);
	return (count);
}
