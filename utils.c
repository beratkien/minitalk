/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:46:05 by beergin           #+#    #+#             */
/*   Updated: 2024/11/29 16:40:36 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n += '0';
		write(1, &n, 1);
	}
}

static int	ft_check(unsigned long long result, const char *str, int sign,
		int i)
{
	if (result > 922337203685477580 || (result == 922337203685477580 && (str[i]
				- '0') > 7))
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	else
		return (1);
}

static int	ft_white_space(int i, const char *str)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int			sign;
	int			re;

	i = 0;
	result = 0;
	sign = 1;
	re = 0;
	i += ft_white_space(i, str);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		re = ft_check(result, str, sign, i);
		if (re == -1 || re == 0)
			return (re);
		result = ((result * 10) + (str[i++] - 48));
	}
	return ((int)(result * sign));
}
