/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:31:10 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/05 14:46:31 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//0. ➜ at start				valid prompt -> green, bad promt -> red
//1. get username			cyan
//2. get current folder		blue
//3. ✗ or % at the end		yellow
void	terminal_prompt(char *type)
{
	if (ft_strncmp(type, "startup", 7) == 0)
		ft_printf(BOLD GREEN "➜  " BLUE "%s " CYAN "minishell" YELLOW " ✗ " C_END, getenv("USER"));
	else if (ft_strncmp(type, "in_loop", 7) == 0)
		ft_printf(BOLD GREEN "➜  " BLUE "%s " CYAN "minishell" YELLOW " ✗ " C_END, getenv("USER"));
}