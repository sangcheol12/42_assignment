/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchep <sangchep@student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:26:18 by sangchep          #+#    #+#             */
/*   Updated: 2023/08/23 02:14:41 by sangchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
//#include "../printf/ft_printf.h"
//#include "../libft/libft.h"
#include <stdio.h>

static void	send_bit(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 100 || pid > 99998)
		{
			//ft_printf("pid value out of range\n");
			printf("pid %d value out of range\n", pid);
			return (0);
		}
		if (kill(pid, 0) == -1)
		{
			//ft_printf(""Process with PID %d is not running.\n");
			printf("Process with PID %d is not running.\n", pid);
			return (0);
		}
		while (argv[2][i] != '\0')
		{
			send_bit(pid, argv[2][i]);
			i++;
		}
		send_bit(pid, '\n');
	}
}