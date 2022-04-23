/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:18:42 by icastell          #+#    #+#             */
/*   Updated: 2022/04/21 18:20:09 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_limits(char *str, char *limit)
{
	int	i;

	if (ft_strlen(str) == ft_strlen(limit))
	{
		i = 0;
		while (str[i])
		{
			if (str[i] > limit[i])
				return (0);
			i++;
		}
	}
	return (1);
}

static int	ft_check_valid_num(char *str)
{
	char	*cstr;

	cstr = MAX;
	if (str)
	{
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				cstr = &MIN[1];
			str++;
		}
		if (ft_strlen(str) <= ft_strlen(cstr)
			&& ft_strisdigit(str)
			&& ft_limits(str, cstr))
			return (1);
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_check_valid_num(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
