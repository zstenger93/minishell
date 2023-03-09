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
		printf(GREEN "                     WELCOME TO\n");
		printf(RED "   __      __    _________    ___           ___\n");
		printf(RED "  |  |    |  |  |         |  |   |         |   |\n");
		printf(RED "  |  |    |  |  |   ______|  |   |         |   |\n");
		printf(RED "  |  |____|  |  |  |____     |   |         |   |\n");
		printf(RED "  |          |  |       |    |   |         |   |\n");
		printf(RED "  |   ____   |  |   ____|    |   |         |   |\n");
		printf(RED "  |  |    |  |  |  |______   |   |______   |   |______\n");
		printf(RED "  |  |    |  |  |         |  |          |  |          |\n");
		printf(RED "  |__|    |__|  |_________|  |__________|  |__________|\n");
		printf(C_END "\n");
		printf(YELLOW "       ✗" RED
			" This program doesn't take any arguments! " YELLOW "✗\n" C_END);
		printf("\n");
		printf(ITALIC "              Please run it as: ./minishell\n\n" C_END);
		printf(GREEN"       Sincerely,\n" C_END);
		printf(RED "                            Mr. Minishell Community\n" C_END);
		printf("\n");
		exit(EXIT_SUCCESS);
	}
}
