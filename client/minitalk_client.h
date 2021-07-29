/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:17:00 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/24 16:28:48 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# define _XOPEN_SOURCE 600
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <unistd.h>
# include "../libft.h"

typedef struct s_client
{
	int				cpid;
	int				spid;
	volatile int	byte_flag;
}				t_client;

void	ft_putstr(char *s);
void	send_cpid_to_server(int value, t_client *client);

#endif