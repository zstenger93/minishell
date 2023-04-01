/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:53:06 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/01 15:55:33 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals_parent(void)
{
	signal_ctrl_c_parent();
	signal_ctrl_backslash();
}

void	handle_sigint_parent(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(1, "^C\n", 3);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	signal_ctrl_c_parent(void)
{
	struct sigaction	ctrl_c;

	ctrl_c.sa_handler = handle_sigint_parent;
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
}
