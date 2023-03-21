/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:44:20 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 10:52:55 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	open_file(char *type, t_shell *shell, t_token *tokens)
// {
// 	int		fd;
// 	char	*pwd;

// 	if (type[0] == '<' && type[1] == '\0')
// 		fd = open(tokens->token, O_RDONLY);
// 	else if (type[0] == '>' && type[1] == '\0')
// 		fd = open(tokens->token, O_WRONLY | O_CREAT | O_TRUNC, GIVE_PERM_WTH_RW);
// 	else if (type[0] == '>' && type[1] == '>')
// 		fd = open(tokens->token, O_WRONLY | O_CREAT | O_APPEND, GIVE_PERM_WTH_RW);
// 	if (fd = -1)
// 	{
// 		pwd = find_env_var(shell->env_head, "PWD");
// 		p_err("The file %s%s\n", pwd, DNE);
// 		shell->exit_code = 1;
// 		free(pwd);
// 	}
// 	return (fd);
// }
	