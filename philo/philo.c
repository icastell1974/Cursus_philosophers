/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:02:55 by icastell          #+#    #+#             */
/*   Updated: 2022/04/28 20:38:31 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_get_params(int argc, char **argv, t_philo_args *args)
{
	if (argc >= 5 && args)
	{
		args->num_philos = ft_atoi(argv[1]);
		args->time_die = ft_atoi(argv[2]);
		args->time_eat = ft_atoi(argv[3]);
		args->time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			args->num_meals = ft_atoi(argv[5]);
		args->num_philos_no_eated = args->num_philos;
		if (args->num_philos > 0 && args->num_philos <= 200
			&& args->time_die >= 60
			&& args->time_eat >= 60
			&& args->time_sleep >= 60)
			return (1);
	}
	return (0);
}

static void	ft_init_params(t_philo_args *args)
{
	args->num_philos = 0;
	args->time_die = 0;
	args->time_eat = 0;
	args->time_sleep = 0;
	args->num_meals = 0;
	args->death = 0;
	args->num_philos_no_eated = 0;
	args->start = ft_timestamp();
	args->num_mutex_forks = 0;
}

static void	ft_check_params(int argc, t_philo_args *args)
{
	if (args->num_philos <= 0 || args->num_philos > 200)
		ft_error(2);
	if (args->time_die <= 60 || args->time_eat <= 60 || args->time_sleep <= 60)
	{
		ft_error(6);
		if (args->time_die <= 0 || args->time_eat <= 0 || args->time_sleep <= 0)
			ft_error(4);
	}
	if (argc == 6 && args->num_meals <= 0)
		ft_error(5);
}

int	main(int argc, char **argv)
{
	t_philo_args	args;

	ft_init_params(&args);
	if (argc == 5 || argc == 6)
	{
		if (ft_check_args(argc, argv) == 1)
		{
			if (ft_get_params(argc, argv, &args) == 1)
				ft_start_philosophers(&args);
			else
				ft_check_params(argc, &args);
		}
		else
			ft_error(3);
	}
	else
		ft_error(1);
	return (0);
}
