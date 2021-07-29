/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:30:42 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/24 16:19:49 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	send_cpid_to_server(int value, t_client *client)
{
	int				pow;
	int				i;
	unsigned int	usecs;

	pow = 32768;
	i = 16;
	usecs = 500;
	while (i > 0)
	{
		if (value >= pow)
		{
			kill(client->spid, SIGUSR1);
			usleep(usecs);
			value -= pow;
		}
		else
		{
			kill(client->spid, SIGUSR2);
			usleep(usecs);
		}
		pow = pow / 2;
		i--;
	}
}
