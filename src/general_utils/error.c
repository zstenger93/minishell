/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:05:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/25 11:51:59 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	how_to_use(int argc)
{
	if (argc != 1)
	{
		printf(GREEN "\n                     WELCOME TO\n");
		printf(RED "   __      __    _________    ___           ___\n");
		printf(RED "  |  |    |  |  |         |  |   |         |   |\n");
		printf(RED "  |  |    |  |  |   ______|  |   |         |   |\n");
		printf(RED "  |  |____|  |  |  |____     |   |         |   |\n");
		printf(RED "  |          |  |       |    |   |         |   |\n");
		printf(RED "  |   ____   |  |   ____|    |   |         |   |\n");
		printf(RED "  |  |    |  |  |  |______   |   |______   |   |______\n");
		printf(RED "  |  |    |  |  |         |  |          |  |          |\n");
		printf(RED "  |__|    |__|  |_________|  |__________|  |__________|\n");
		print_in();
		print_shell();
		printf(YELLOW "\n       ✗" RED
			" This program doesn't take any arguments! " YELLOW "✗\n" C_END);
		printf("\n");
		printf(ITALIC "              Please run it as: ./minishell\n\n" C_END);
		printf(GREEN"       Sincerely,\n" C_END);
		printf(RED
			"                            Mr. Minishell Community\n" C_END);
		printf("\n");
		exit(EXIT_SUCCESS);
	}
}

void	print_in(void)
{
	printf(YELLOW"        		         ___     \n");
	printf("		     ___        /\\__\\    \n");
	printf("		    /\\  \\      /::|  |   \n");
	printf("		    \\:\\  \\    /:|:|  |   \n");
	printf("		    /::\\__\\  /:/|:|  |__ \n");
	printf("		 __/:/\\/__/ /:/ |:| /\\__\\ \n");
	printf("		/\\/:/  /    \\/__|:|/:/  /\n");
	printf("		\\::/__/         |:/:/  / \n");
	printf("		 \\:\\__\\         |::/  /  \n");
	printf("		  \\/__/         /:/  /   \n");
	printf("		                \\/__/    \n");
}

void	print_shell(void)
{
	printf(BLUE"      ___           ___           ___    "
		"       ___       ___ \n");
	printf("     /\\  \\         /\\__\\         /\\  \\   "
		"      /\\__\\     /\\__\\ "
		"\n");
	printf("    /::\\  \\       /:/  /        /::\\  \\    "
		"   /:/  /    /:/  /\n");
	printf("   /:/\\ \\  \\     /:/__/    "
		"    /:/\\:\\  \\     /:/  /    /:/  / \n");
	printf("  _\\:\\~\\ \\  \\   /::\\  \\ ___ "
		"  /::\\~\\:\\  \\   /:/  /    /:/  /  \n");
	printf(" /\\ \\:\\ \\ \\__\\ /:/\\:\\  /\\_"
		"_\\ /:/\\:\\ \\:\\__\\ /:/__/    /:/__/   \n");
	printf(" \\:\\ \\:\\ \\/__/ \\/__\\:\\/:/ "
		" / \\:\\~\\:\\ \\/__/ \\:\\  \\    \\:\\  \\   \n");
	printf("  \\:\\ \\:\\__\\        \\::/  / "
		"  \\:\\ \\:\\__\\    \\:\\  \\    \\:\\  \\  \n");
	printf("   \\:\\/:/  /        /:/  /  "
		"   \\:\\ \\/__/     \\:\\  \\    \\:\\  \\ \n");
	printf("    \\::/  /        /:/  /   "
		"    \\:\\__\\        \\:\\__\\    \\:\\__\\ "
		"\n");
	printf("     \\/__/         \\/__/    "
		"     \\/__/         \\/__/     \\/__/\n");
}
