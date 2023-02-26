/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:05:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/02/26 17:15:30 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	how_to_use(void)
{
	printf(RED "✗ This program doesn't take any arguments! ✗\n" C_END);
	printf(YELLOW "       Please run it as: ./minishell\n" C_END);
	exit(EXIT_SUCCESS);
}
