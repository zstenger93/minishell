/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:05:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/06 12:34:46 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	how_to_use(int argc)
{
	if (argc != 1)
	{
		printf(RED "✗ This program doesn't take any arguments! ✗\n" C_END);
		printf(YELLOW "       Please run it as: ./minishell\n\n" C_END);
		printf(GREEN"Sincerely,\n" C_END);
		printf(RED "                     Mr. Minishell Community\n" C_END);
		exit(EXIT_SUCCESS);
	}
}
