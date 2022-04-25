/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:41 by icastell          #+#    #+#             */
/*   Updated: 2022/04/25 18:08:50 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_create_philosophers(t_philo_args *args)
{
	int	i;

	i = 0;
	args->philo = ft_calloc(args->num_philos, sizeof(t_philo));
	while (i < args->num_philos)
	{
		args->philo[i].id = i;
		args->philo[i].left_fork = args->philo[i].id;
		args->philo[i].right_fork = (args->philo[i].left_fork + 1)
			% args->num_philos;
		args->philo[i].num_eatings = 0;
		args->philo[i].max_num_meals = args->num_meals;
		args->philo[i].died = 0;
		args->philo[i].last_meal = ft_timestamp();
		args->philo[i].args = args;
		i++;
	}
	return ;
}

static void	ft_destroy_philosophers(t_philo_args *args)
{
	int	i;
	int	num_forks_to_destroy;

	i = 0;
	num_forks_to_destroy = 0;
	pthread_mutex_destroy(&args->lock);
	if (args->num_mutex_forks == 0)
		num_forks_to_destroy = args->num_philos;
	else
		num_forks_to_destroy = args->num_mutex_forks;
	while (i < num_forks_to_destroy)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	if (args->forks)
		free(args->forks);
	if (args->philo)
		free(args->philo);
	return ;
}

void	ft_start_philosophers(t_philo_args *args)
{
	if (ft_mutex_init_lock(args) == 1)
		ft_error(7);
	else if (ft_mutex_init_forks(args) == 1)
	{
		ft_error(7);
		ft_destroy_philosophers(args);
	}
	else
	{
		ft_create_philosophers(args);
		ft_create_pthreads(args);
		ft_loop(args);
		ft_destroy_philosophers(args);
	}
	return ;
}
