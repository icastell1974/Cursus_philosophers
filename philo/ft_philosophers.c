/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:41 by icastell          #+#    #+#             */
/*   Updated: 2022/03/29 20:23:07 by icastell         ###   ########.fr       */
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
}

static void	ft_destroy_philosophers(t_philo_args *args)
{
	pthread_mutex_destroy(&args->lock);
	free(args->forks);
	free(args->philo);
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
	pthread_mutex_init(&args->lock, NULL);
	ft_create_philosophers(args);
	ft_print_philosophers(args);
	ft_destroy_philosophers(args);
}