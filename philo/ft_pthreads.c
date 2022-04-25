/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthreads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:36:52 by icastell          #+#    #+#             */
/*   Updated: 2022/04/25 18:14:13 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_start_living_philos(void *arg)
{
	t_philo	*filosofo;

	filosofo = (t_philo *)arg;
	usleep(250);
	filosofo->last_meal = ft_timestamp();
	while (!filosofo->args->death && filosofo->args->num_philos_no_eated)
	{
		if (!filosofo->args->death)
			ft_eat(filosofo);
		else
			break ;
		filosofo->num_eatings++;
		if (filosofo->max_num_meals
			&& (filosofo->num_eatings == filosofo->max_num_meals))
		{
			pthread_mutex_lock(&filosofo->args->lock);
			filosofo->args->num_philos_no_eated--;
			pthread_mutex_unlock(&filosofo->args->lock);
			break ;
		}
		ft_sleep_and_think(filosofo);
	}
	return (0);
}

void	ft_create_pthreads(t_philo_args *args)
{
	int	i;

	i = 0;
	while (i < args->num_philos)
	{
		if (pthread_create(&args->philo[i].thread_id,
				NULL, ft_start_living_philos, &args->philo[i]) != 0)
		{
			ft_error(8);
			return ;
		}
		usleep(250);
		i++;
	}
	return ;
}

void	ft_loop(t_philo_args *args)
{
	int	i;

	while (!args->death && args->num_philos_no_eated)
	{
		i = 0;
		while (i < args->num_philos && !args->death
			&& args->num_philos_no_eated)
		{
			if ((int)(ft_timestamp() - args->philo[i].last_meal)
				> args->time_die && args->num_philos_no_eated)
			{
				pthread_mutex_lock(&args->lock);
				args->death = 1;
				pthread_mutex_unlock(&args->lock);
				usleep(100);
				ft_print_philo(&args->philo[i], H_DIED);
			}
			usleep(100);
			i++;
		}
	}
}
