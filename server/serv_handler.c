/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:43:09 by dmazurki          #+#    #+#             */
/*   Updated: 2021/07/24 16:26:48 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_serv.h"

void	serv1_handler(int signo)
{
	general_handler('1');
	(void)signo;
}

void	serv2_handler(int signo)
{
	general_handler('0');
	(void)signo;
}
