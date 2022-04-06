/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:55:17 by icastell          #+#    #+#             */
/*   Updated: 2022/04/01 18:37:12 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	ft_timestamp(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

uint64_t	ft_timediff(uint64_t t_present, u_int64_t t_past)
{
	return (t_present - t_past);
}

/*void	my_usleep(t_philo_args *args, uint64_t action_time)
{
	uint64_t	current_time;
	uint64_t	total_time_passed;

	current_time = timestamp();
	total_time_passed = current_time + action_time;
	while (current_time < total_time_passed)
	{
		if (philo->info->is_dead)
			break ;
		current_time = timestamp();
		usleep(action_time);
	}
}*/