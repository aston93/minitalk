/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:44:42 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/24 16:24:00 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_serv.h"

t_serv	g_server;

static void	pid_handler_serv(void)
{
	g_server.spid = getpid();
	ft_memset(g_server.byte, 0, 9);
	ft_memset(g_server.cpid_bits, 0, 16);
	ft_printf("Server PID: %d\n", g_server.spid);
}

void	general_handler(char c)
{
	if (g_server.cpid_check)
	{
		g_server.cpid_bits[g_server.i] = c;
		(g_server.i)++;
		if (g_server.i == 16)
		{
			g_server.i = 0;
			g_server.cpid = cpid_bits_to_int(&g_server);
		}
	}
	else
	{
		g_server.byte[g_server.i] = c;
		(g_server.i)++;
		if (g_server.i == 8)
		{
			g_server.i = 0;
			print_char(&g_server);
		}
		usleep(2);
		send_sig_recieved_conrifm_to_client(&g_server);
	}
}

int	main(void)
{
	struct sigaction	s1;
	struct sigaction	s2;

	g_server.i = 0;
	g_server.val = 0;
	g_server.cpid_check = 1;
	pid_handler_serv();
	s1.sa_handler = serv1_handler;
	s2.sa_handler = serv2_handler;
	s1.sa_flags = SA_SIGINFO;
	s2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s2, NULL);
	while (1)
		pause();
	return (0);
}
