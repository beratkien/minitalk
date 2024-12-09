/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:45:04 by beergin           #+#    #+#             */
/*   Updated: 2024/11/29 16:31:37 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_control(int sig)
{
	static int	bit_count = 0;
	static char	temp_bit = 0;

	if (sig == SIGUSR2)
		temp_bit |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &temp_bit, 1);
		bit_count = 0;
		temp_bit = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Proccess ID (PID): ");
	ft_putnbr(pid);
	ft_putstr("\n");
	signal(SIGUSR1, ft_control);
	signal(SIGUSR2, ft_control);
	while (1)
		pause();
	return (0);
}
