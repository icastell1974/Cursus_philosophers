/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_philo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:10:38 by icastell          #+#    #+#             */
/*   Updated: 2022/04/23 22:04:51 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(size_t value)
{
	if (value == 1)
		ft_putstr_fd(ERROR_1, 1);
	else if (value == 2)
		ft_putstr_fd(ERROR_2, 1);
	else if (value == 3)
		ft_putstr_fd(ERROR_3, 1);
	else if (value == 4)
		ft_putstr_fd(ERROR_4, 1);
	else if (value == 5)
		ft_putstr_fd(ERROR_5, 1);
	else if (value == 6)
		ft_putstr_fd(ERROR_6, 1);
	else if (value == 7)
		ft_putstr_fd(ERROR_7, 1);
	else if (value == 8)
		ft_putstr_fd(ERROR_8, 1);
	return ;
}

void	ft_print_philosophers(t_philo_args *args)
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
		printf("   Nº de mutex_forks inicializados: %d\n",
			args->num_mutex_forks);
		i++;
	}
}

void	ft_print_philo(t_philo *philo, char *status)
{
	ft_putnbr_fd(ft_timestamp() - philo->args->start, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(philo->id + 1, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(status, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

void	ft_print_status(t_philo *philo, char *status)
{
	if (!philo->args->death && philo->args->num_philos_no_eated)
	{
		pthread_mutex_lock(&philo->args->lock);
		ft_print_philo(philo, status);
		pthread_mutex_unlock(&philo->args->lock);
	}
	/*else if (philo->args->death)
	{
		pthread_mutex_lock(&philo->args->lock);
		ft_print_philo(philo, H_DIED);
		pthread_mutex_unlock(&philo->args->lock);
	}
	else if (!philo->args->death && !philo->args->num_meals)
	{
		pthread_mutex_lock(&philo->args->lock);
		ft_print_philo(philo, H_ALL_EATINGS);
		pthread_mutex_unlock(&philo->args->lock);
	}*/
	return ;
}
