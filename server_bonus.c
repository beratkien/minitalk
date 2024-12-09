/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:13:29 by beergin           #+#    #+#             */
/*   Updated: 2024/11/29 16:38:39 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_control(int sig, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	temp_bit = 0;

	(void)context;
	if (sig == SIGUSR2)
		temp_bit |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (temp_bit == '\n')
			kill(info->si_pid, SIGUSR1);
		write(1, &temp_bit, 1);
		bit_count = 0;
		temp_bit = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	ft_putstr("Proccess ID (PID): ");
	ft_putnbr(pid);
	ft_putstr("\n");
	act.sa_sigaction = ft_control;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
