/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers_actions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:08:16 by icastell          #+#    #+#             */
/*   Updated: 2022/04/23 22:28:34 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_pickup_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->forks[philo->left_fork]));
	ft_print_status(philo, H_TAKE_FORK);
	if (philo->left_fork != philo->right_fork && !philo->args->death)
	{
		pthread_mutex_lock(&(philo->args->forks[philo->right_fork]));
		ft_print_status(philo, H_TAKE_FORK);
		return (1);
	}
	else
	{
		ft_usleep(philo->args, philo->args->time_die + 40);
		return (0);
	}
}

void	ft_putdown_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->args->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->args->forks[philo->right_fork]));
	return ;
}

void	ft_sleep_and_think(t_philo *philo)
{
	if (!philo->args->death && philo->args->num_philos_no_eated)
		ft_print_status(philo, H_SLEEPING);
	if (!ft_usleep(philo->args, philo->args->time_sleep)
		&& !philo->args->death && philo->args->num_philos_no_eated)
		ft_print_status(philo, H_THINKING);
	return ;
}

void	ft_eat(t_philo *philo)
{
	if (!philo->args->death && ft_pickup_forks(philo))
	{
		ft_print_status(philo, H_EATING);
		if (!ft_usleep(philo->args, philo->args->time_eat))
			ft_putdown_forks(philo);
		else
		{
			ft_putdown_forks(philo);
			return ;
		}
		philo->last_meal = ft_timestamp();
	}
	else
		ft_putdown_forks(philo);
	return ;
}
