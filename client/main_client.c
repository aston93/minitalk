/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:13:32 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/24 16:28:28 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

t_client	g_client;

void	s1_handler(int signo)
{
	g_client.byte_flag = 0;
	(void)signo;
}

void	s2_handler(int signo)
{
	ft_putstr("Message recieved !\n");
	(void)signo;
	exit(0);
}

void	pid_handler_client(t_client *client, int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Error ! Wrong number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	client->spid = ft_atoi(argv[1]);
	client->cpid = getpid();
}

static void	dec_to_bin_and_send(unsigned char value, t_client *client)
{
	int	pow;
	int	i;

	pow = 128;
	i = 8;
	while (i > 0)
	{
		if (value >= pow)
		{
			kill(client->spid, SIGUSR1);
			pause();
			value -= pow;
		}
		else
		{
			kill(client->spid, SIGUSR2);
			pause();
		}
		pow = pow / 2;
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int					i;
	struct sigaction	s1;
	struct sigaction	s2;

	s1.sa_handler = s1_handler;
	s2.sa_handler = s2_handler;
	s1.sa_flags = SA_SIGINFO;
	s2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s2, NULL);
	i = 0;
	pid_handler_client(&g_client, argc, argv);
	send_cpid_to_server(g_client.cpid, &g_client);
	while (argv[2][i])
	{
		dec_to_bin_and_send((char)argv[2][i], &g_client);
		i++;
	}
	dec_to_bin_and_send((char)argv[2][i], &g_client);
	while (1)
		pause();
	return (0);
}
