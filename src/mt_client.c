/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:35:35 by ejafer            #+#    #+#             */
/*   Updated: 2022/02/03 16:58:38 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_send(int spid, char *str)
{
	int	i;

	while (*str)
	{
		kill(spid, SIGUSR1);
		usleep(6);
		i = 0b10000000;
		while (i)
		{
			if (i & *str)
				kill(spid, SIGUSR1);
			else
				kill(spid, SIGUSR2);
			i >>= 1;
			usleep(5);
		}
		str++;
	}
	kill(spid, SIGUSR2);
	usleep(5);
}

void	sighandler(int signal)
{
	(void ) signal;
	return ;
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	act.sa_handler = &sighandler;
	if (argc != 3)
		return (0);
	sigaction(SIGUSR1, &act, NULL);
	mt_send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
