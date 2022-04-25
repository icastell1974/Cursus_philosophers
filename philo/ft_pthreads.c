/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthreads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:36:52 by icastell          #+#    #+#             */
/*   Updated: 2022/04/25 17:17:20 by icastell         ###   ########.fr       */
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
		if (pthread_create(&args->philo[i].thread_id, NULL,//ft_kk, &args->philo[i].id) != 0)
			ft_start_living_philos, &args->philo[i]) != 0)
		{
			ft_error(8);
			return ;
		}
		usleep(250);
		//else
		//	pthread_join(args->philo[i].thread_id, NULL);
		i++;
	}
	//ft_check_if_dead(t_philo_args *args);
	return ;
}

void	ft_loop(t_philo_args *args)
{
	int		i;
	//int		meals;
	//t_philo	filosofo;
	
	//meals = args->num_meals;
	while (!args->death && args->num_philos_no_eated)
	{
		i = 0;
		while (i < args->num_philos && !args->death
			&& args->num_philos_no_eated)
		{
			//filosofo = args->philo[i];
			if ((int)(ft_timestamp() - args->philo[i].last_meal)
				> args->time_die && args->num_philos_no_eated)
			{
				pthread_mutex_lock(&args->lock);
				args->death = 1;
				pthread_mutex_unlock(&args->lock);
				usleep(100);
				//if (args->num_meals > 0 && meals)
				ft_print_philo(&args->philo[i], H_DIED);
			}
			usleep(100);
			i++;
		}
	}
}
