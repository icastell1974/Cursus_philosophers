/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:02:55 by icastell          #+#    #+#             */
/*   Updated: 2022/03/23 16:38:32 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_get_params(int argc, char **argv, t_philo_args *philo)
{
	if (argc >= 5 && philo)
	{
		philo->num_philos = ft_atoi(argv[1]);
		philo->time_die = ft_atoi(argv[2]);
		philo->time_eat = ft_atoi(argv[3]);
		philo->time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo->num_meals = ft_atoi(argv[5]);
		if (philo->num_philos > 1 && philo->num_philos <= 200
			&& philo->time_die >= 60
			&& philo->time_eat >= 60
			&& philo->time_sleep >= 60)
			return (1);
	}
	return (0);
}

static void	ft_init_params(t_philo_args *philo)
{
	philo->num_philos = 0;
	philo->time_die = 0;
	philo->time_eat = 0;
	philo->time_sleep = 0;
	philo->num_meals = 0;
}

static void	ft_check_params(int argc, t_philo_args *philo)
{
	if (philo->num_philos <= 0 || philo->num_philos > 200)
		ft_error(2);
	if (philo->time_die <= 60 || philo->time_eat <= 60 || philo->time_sleep <= 60)
	{
		ft_error(6);
		if (philo->time_die <= 0 || philo->time_eat <= 0 || philo->time_sleep <= 0)
			ft_error(4);
	}
	if (argc == 6 && philo->num_meals <= 0)
		ft_error(5);
}

int	main(int argc, char **argv)
{
	t_philo_args	philo;
	int	i;

	i = 0;
	ft_init_params(&philo);
	if (argc == 5 || argc == 6)
	{
		if (ft_check_args(argc, argv) == 1)
		{
			if (ft_get_params(argc, argv, &philo) == 1)
			{
				printf("todo ha ido bien. Debo empezar con los hilos\n");
				printf("nº de argumentos: %d\n", argc);
				while (i < argc)
				{
					printf("argumentos: %s\n", argv[i]);
					i++;
				}
				printf("num_philos: %d\n", philo.num_philos);
				printf("num_time_die: %d\n", philo.time_die);
				printf("num_time_eat: %d\n", philo.time_eat);
				printf("num_time_sleep: %d\n", philo.time_sleep);
				printf("num_meals: %d\n", philo.num_meals);
			}
			else
				ft_check_params(argc, &philo);
		}
		else
			ft_error(3);
	}
	else//if ((argc == 1) || (argc > 6))
		ft_error(1);
	return (0);
}