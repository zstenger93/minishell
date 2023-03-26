/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:01:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/21 18:57:59 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals(void)
{
	struct sigaction	ctrl_c;
	struct sigaction	ctrl_back_slash;
	struct termios		sett;
	struct termios		term;

	tcgetattr(1, &sett);
	sett.c_lflag &= ~ECHOCTL;
	tcsetattr(1, TCSAFLUSH, &sett);
	ctrl_c.sa_handler = handle_sigint;
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
	ctrl_back_slash.sa_handler = SIG_IGN;
	ctrl_back_slash.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_back_slash.sa_mask);
	sigaction(SIGQUIT, &ctrl_back_slash, NULL);
}

void	handle_sigint(int sig_num)
{
	if (sig_num == SIGINT)
	{
		rl_on_new_line();
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
