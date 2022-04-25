/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:41:21 by icastell          #+#    #+#             */
/*   Updated: 2022/04/25 17:15:51 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>

# define MAX "2147483647"
# define MIN "-2147483648"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define H_TAKE_FORK "has taken a fork"
# define H_EATING "is eating"
# define H_SLEEPING "is sleeping"
# define H_THINKING "is thinking"
# define H_DIED "death"
# define H_ALL_EATINGS "all philosophers have eaten"

# define ERROR_1 "Wrong number of arguments:\nnumber of philosophers, \
time to die, time to eat, time to sleep and [number of meals] are expected\n"
# define ERROR_2 "The number of philosophers must be greater than 0 \
and less than or equal to 200\n"
# define ERROR_3 "Parameters must be numeric\n"
# define ERROR_4 "Time to die, time to eat and time to sleep \
must be positive\n"
# define ERROR_5 "The number of meals must be positive\n"
# define ERROR_6 "Time to die, time to eat and time to sleep \
must be greater than 60\n"
# define ERROR_7 "Failed to initialize mutex\n"
# define ERROR_8 "Failed to create threads\n"

typedef struct s_philo_args
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_meals;
	int				num_philos_no_eated;
	int				death;
	uint64_t		start;
	pthread_mutex_t	*forks;
	int				num_mutex_forks;
	pthread_mutex_t	lock;
	struct s_philo	*philo;
}				t_philo_args;

typedef struct s_philo
{
	int					id;
	int					left_fork;
	int					right_fork;
	int					num_eatings;
	int					max_num_meals;
	int					died;
	uint64_t			last_meal;
	pthread_t			thread_id;
	struct s_philo_args	*args;
}				t_philo;


void		ft_error(size_t value);
size_t		ft_strlen(char *str);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_check_args(int argc, char **argv);
void		ft_start_philosophers(t_philo_args *args);
int			ft_mutex_init_lock(t_philo_args *args);
int			ft_mutex_init_forks(t_philo_args *args);
void		ft_print_philo(t_philo *philo, char *status);
void		ft_print_status(t_philo *philo, char *status);
void		ft_print_philosophers(t_philo_args *args); //esta función hay que borrarla
uint64_t    ft_timestamp(void);
//uint64_t	ft_timediff(uint64_t t_present, u_int64_t t_past);
int			ft_usleep(t_philo_args *args, uint64_t time);
void		ft_create_pthreads(t_philo_args *args);
void		ft_loop(t_philo_args *args);
void		ft_eat(t_philo *philo);
void		ft_sleep_and_think(t_philo *philo);
int			ft_pickup_forks(t_philo *philo);
void		ft_putdown_forks(t_philo *philo);

#endif