/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:31:23 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 17:56:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	kill_fail(void)
{
	ft_printf("Sending signal failed\n");
	exit(1);
}

static void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				index;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << index);
	index++;
	if (index == 8)
	{
		ft_printf("%c", c);
		index = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
	{
		if (kill(info->si_pid, SIGUSR1) < 0)
			kill_fail();
	}
	else if (sig == SIGUSR2)
	{
		if (kill(info->si_pid, SIGUSR2) < 0)
			kill_fail();
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) < 0)
		return (ft_printf("sigemptyset() failed\n"), 1);
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		return (ft_printf("sigaction() failed\n"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
		return (ft_printf("sigaction() failed\n"), 1);
	while (1)
		pause();
	return (0);
}
