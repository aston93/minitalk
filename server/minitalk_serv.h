/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_serv.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:17:00 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/24 16:04:34 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERV_H
# define MINITALK_SERV_H

// # define _XOPEN_SOURCE 700
# define _XOPEN_SOURCE 600
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <unistd.h>
# include "../libft.h"

typedef struct s_serv
{
	int		spid;
	int		cpid;
	int		i;
	char	byte[9];
	char	cpid_bits[17];
	int		val;
	int		cpid_check;
}				t_serv;

void	send_sig_recieved_conrifm_to_client(t_serv *server);
void	send_msg_recieved_conrifm_to_client(t_serv *server);
int		cpid_bits_to_int(t_serv *server);
void	ft_putstr(char *s);
void	serv1_handler(int signo);
void	serv2_handler(int signo);
void	general_handler(char c);
void	print_char(t_serv *server);

#endif