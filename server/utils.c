/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:30:42 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/28 18:34:43 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_serv.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	print_char(t_serv *server)
{
	char	tmp;
	int		value_int;
	int		i;
	int		pow;

	value_int = 0;
	i = 0;
	pow = 128;
	while (i < 7)
	{
		if (server->byte[i] == '1')
			value_int += pow;
		i++;
		pow = pow / 2;
	}
	if (server->byte[7] == '1')
		value_int++;
	tmp = (char)value_int;
	write(1, &tmp, 1);
	if (value_int == 0)
	{
		send_msg_recieved_conrifm_to_client(server);
		server->cpid_check = 1;
	}
	ft_memset(server->byte, 0, 8);
}

void	send_sig_recieved_conrifm_to_client(t_serv *server)
{
	kill(server->cpid, SIGUSR1);
}

void	send_msg_recieved_conrifm_to_client(t_serv *server)
{
	kill(server->cpid, SIGUSR2);
}

int	cpid_bits_to_int(t_serv *server)
{
	int		result;
	int		i;
	int		pow;

	result = 0;
	i = 0;
	pow = 32768;
	while (i < 15)
	{
		if (server->cpid_bits[i] == '1')
			result += pow;
		i++;
		pow = pow / 2;
	}
	if (server->cpid_bits[15] == '1')
		result++;
	server->cpid_check = 0;
	return (result);
}
