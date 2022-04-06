/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:41:21 by icastell          #+#    #+#             */
/*   Updated: 2022/04/05 19:18:33 by icastell         ###   ########.fr       */
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
# include <mlx.h>
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
# define H_DIED "died"

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
	int				death;
	int				num_philos_eated;
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
int			ft_check_args(int argc, char **argv);
void		ft_start_philosophers(t_philo_args *args);
int			ft_mutex_init_lock(t_philo_args *args);
int			ft_mutex_init_forks(t_philo_args *args);
void		ft_print_philosophers(t_philo_args *args);
uint64_t    ft_timestamp(void);
uint64_t	ft_timediff(uint64_t t_present, u_int64_t t_past);
//void		*ft_kk(void *arg);

/*int		ft_check_extension(char	*map_name);
int		ft_get_map(t_mapa *mapa, char *filename);
void	ft_read_map_file(t_mapa *mapa, char *filename);
void	ft_check_map(t_mapa *mapa);
int		ft_map_heigth(char **map);
void	ft_map_width(t_mapa *mapa);
void	ft_free_all(t_so_long *game);
int		ft_render(t_so_long *game);
void	ft_load_images(t_so_long *game);
void	ft_draw_wall(t_so_long *game, int y, int x);
void	ft_draw_empty_space(t_so_long *game, int y, int x);
void	ft_draw_collectible(t_so_long *game, int y, int x);
void	ft_draw_exit(t_so_long *game, int y, int x);
void	ft_draw_player(t_so_long *game, int y, int x);
int		ft_close(t_so_long *game);
int		ft_key_press(int key_code, t_so_long *game);
void	ft_get_player(t_mapa *mapa);
void	ft_key_up(t_so_long *game);
void	ft_key_down(t_so_long *game);
void	ft_key_left(t_so_long *game);
void	ft_key_right(t_so_long *game);*/

#endif