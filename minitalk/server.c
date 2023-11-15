/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchep <sangchep@student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:26:25 by sangchep          #+#    #+#             */
/*   Updated: 2023/08/23 01:13:29 by sangchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
//#include "../printf/ft_printf.h"
//#include "../libft/libft.h"
#include <stdio.h>

int	send_checker;

static void	signal_handler(int signo)
{
	static int	bit;
	static char	message;

	if (signo == SIGUSR1)
		message |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		//ft_printf("%c", message);
		printf("%c", message);
		bit = 0;
		message = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	//ft_printf("%d", pid);
	printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}