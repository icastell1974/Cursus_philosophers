/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:41 by icastell          #+#    #+#             */
/*   Updated: 2022/03/31 20:50:06 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_create_philosophers(t_philo_args *args)
{
	int i;

	i = 0;
	args->forks = ft_calloc(args->num_philos, sizeof(pthread_mutex_t));
	args->philo = ft_calloc(args->num_philos, sizeof(t_philo));
	while (i < args->num_philos)
	{
		args->philo[i].id = i + 1;
		args->philo[i].left_fork = args->philo[i].id;
		if (args->philo[i].id == args->num_philos)
			args->philo[i].right_fork = 1;
		else
			args->philo[i].right_fork = args->philo[i].left_fork + 1;
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

	pthread_mutex_destroy(&args->lock);
	i = args->num_philos;
	while (args->num_philos > 0 && --i >=0)
		pthread_mutex_destroy(&args->forks[i]);
	free(args->forks);
	free(args->philo);
	return ;
}

static int	ft_mutex_init(t_philo_args *args)
{
	int	i;
	
	i = 0;
	if (pthread_mutex_init(&args->lock, NULL) != 0)
		return (1);
	while (i < args->num_philos)
	{
		if (pthread_mutex_init(&args->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_print_philosophers(t_philo_args *args)
{
	int	i;

	i = 0;
	while (i < args->num_philos)
	{
		printf("Filósofo %d:\n", args->philo[i].id);
		printf("   Tenedor izdo.: %d\n", args->philo[i].left_fork);
		printf("   Tenedor dcho.: %d\n", args->philo[i].right_fork);
		printf("   Nº de comidas: %d\n", args->philo[i].num_eatings);
		printf("   Nº máx. de comidas: %d\n", args->philo[i].max_num_meals);
		printf("   ¿Está muerto?: %d\n", args->philo[i].died);
		printf("   Instante de última comida: %lld\n", args->philo[i].last_meal);
		i++;
	}
}

void    ft_start_philosophers(t_philo_args *args)
{
	if (ft_mutex_init(args) == 1)
		ft_error(7);
	else
	{
		ft_create_philosophers(args);
		ft_print_philosophers(args);
		ft_destroy_philosophers(args);
	}
	return ;
}