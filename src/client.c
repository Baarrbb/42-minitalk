/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:31:27 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 17:56:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	kill_fail(void)
{
	ft_printf("Sending signal failed\n");
	exit(1);
}

static void	confirmation_handler(int sigsent)
{
	(void)sigsent;
}

static void	send(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) < 0)
				kill_fail();
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				kill_fail();
		}
		usleep(20000);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
	{
		ft_printf(RED);
		ft_printf("[ERROR]\n");
		ft_printf(RESET);
		ft_printf("Usage : ./client [PID_server] [String]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Unexpected error on PID\n");
		return (1);
	}
	i = -1;
	signal(SIGUSR1, confirmation_handler);
	signal(SIGUSR2, confirmation_handler);
	while (argv[2][++i])
		send(pid, argv[2][i]);
	send(pid, '\n');
	return (0);
}
