/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:10:38 by icastell          #+#    #+#             */
/*   Updated: 2022/03/22 21:07:06 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
	return ;
}

void	ft_error(size_t value)
{
	if (value == 1)
		ft_putstr_fd(ERROR_1, 1);
	else if (value == 2)
		ft_putstr_fd(ERROR_2, 1);
	else if (value == 3)
		ft_putstr_fd(ERROR_3, 1);
	else if (value == 4)
		ft_putstr_fd(ERROR_4, 1);
	else if (value == 5)
		ft_putstr_fd(ERROR_5, 1);
	else if (value == 6)
		ft_putstr_fd(ERROR_6, 1);
}