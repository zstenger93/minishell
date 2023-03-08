/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:02:03 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/08 11:01:26 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	exit_shell(t_shell *shell)
{
	if (is_wrong_command(shell->trimmed_prompt, ' ') > 2)
		return ;
	if (ft_strcmp(shell->trimmed_prompt, "exit") == 1
		&& ft_strncmp(shell->trimmed_prompt, "exit ", 5) != 0)
	{
		free_at_exit(shell);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(shell->trimmed_prompt, "exit ", 5) == 0)
		exit_code(shell);
}

void	exit_code(t_shell *shell)
{
	int		i;
	int		len;
	int		code;
	char	*code_str;

	i = 5;
	len = ft_strlen(shell->trimmed_prompt + i);
	code_str = (char *)malloc(sizeof(char) * (len + 1));
	strcpy(code_str, shell->trimmed_prompt + i);
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
		printf("exit: too many arguments\n");
	return (count);
}
