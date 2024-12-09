/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:13:26 by beergin           #+#    #+#             */
/*   Updated: 2024/11/29 16:36:34 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_received_message(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("Received message!\n");
}

static void	ft_to_server(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_putstr("Yanlış ya da eksik argüman! Şu şekilde düzeltin: ");
		ft_putstr("./client <server_pid> <message>\n");
		return (1);
	}
	signal(SIGUSR1, ft_received_message);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
		ft_to_server(pid, *str++);
	ft_to_server(pid, '\n');
	return (0);
}
