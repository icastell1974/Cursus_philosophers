/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:10:38 by icastell          #+#    #+#             */
/*   Updated: 2022/03/22 20:06:12 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	int	digit;

	if ((c >= '0') && (c <= '9'))
		digit = 1;
	else
		digit = 0;
	return (digit);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	numero;
	int		negativo;

	i = 0;
	numero = 0;
	negativo = 1;
	while ((str[i] == ' ') || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			negativo *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (numero * negativo > 2147483647)
			return (-1);
		if (numero * negativo < -2147483648)
			return (0);
		numero = numero * 10 + str[i] - '0';
		i++;
	}
	return (numero * negativo);
}
