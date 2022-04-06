/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:58:18 by icastell          #+#    #+#             */
/*   Updated: 2022/04/05 19:00:40 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_init_lock(t_philo_args *args)
{
	if (pthread_mutex_init(&args->lock, NULL) != 0)
		return (1);
	return (0);
}

int	ft_mutex_init_forks(t_philo_args *args)
{
	int	i;
	
	i = 0;
	args->forks = ft_calloc(args->num_philos, sizeof(pthread_mutex_t));
	while (i < args->num_philos)
	{
		if (pthread_mutex_init(&args->forks[i], NULL) != 0)
		{
			args->num_mutex_forks = i;
			return (1);
		}
		i++;
	}
	return (0);
}
