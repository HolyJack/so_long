/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:35:18 by ejafer            #+#    #+#             */
/*   Updated: 2022/02/03 17:41:12 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_initdata(void)
{
	g_data.c = 0;
	g_data.str[0] = 0;
	g_data.s_index = 0;
	g_data.bits = 0;
}

void	active_transition(int signal)
{
	if (signal == SIGUSR1)
			g_data.c = g_data.c << 1 | 0b1;
	if (signal == SIGUSR2)
			g_data.c = g_data.c << 1 | 0b0;
	if (!--g_data.bits)
	{
		g_data.str[g_data.s_index] = g_data.c;
		g_data.c = 0b0;
		g_data.s_index++;
		g_data.str[g_data.s_index] = 0;
	}
}

void	change_transition_status(int signal)
{
	if (signal == SIGUSR1)
			g_data.bits = 8;
	if (signal == SIGUSR2)
	{
		ft_putstr(g_data.str);
		mt_initdata();
	}
}

void	mt_sighandler(int signal, siginfo_t *info, void *context)
{
	(void) context;
	if (g_data.bits != 0)
		active_transition(signal);
	else
		change_transition_status(signal);
	kill(info->si_pid, SIGUSR1);
	usleep(5);
}

int	main(void)
{
	const int			pid = getpid();
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &mt_sighandler;
	mt_initdata();
	ft_putnbr((int) pid);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		;
	return (0);
}
