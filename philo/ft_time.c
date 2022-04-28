/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:55:17 by icastell          #+#    #+#             */
/*   Updated: 2022/04/28 20:34:13 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	ft_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	ft_usleep(t_philo_args *args, uint64_t time)
{
	uint64_t	total_time;
	uint64_t	now;

	now = ft_timestamp();
	total_time = now + time;
	while (now < total_time && !args->death)
	{
		now = ft_timestamp();
		usleep(time);
	}
	if (args->death || !args->num_philos_no_eated)
		return (1);
	return (0);
}
