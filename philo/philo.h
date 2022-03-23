/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:41:21 by icastell          #+#    #+#             */
/*   Updated: 2022/03/22 21:10:50 by icastell         ###   ########.fr       */
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

typedef struct s_philo_args
{
	int	num_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_meals;
}				t_philo_args;

typedef struct s_lista
{
	struct s_nodo	*head;
	int				length;
}			t_lista;

typedef struct s_mapa
{
	char				**map;
	int					width;
	int					height;
	int					num_collectible;
	int					num_exit;
	int					num_player;
	int					x_player;
	int					y_player;
	int					count;
	int					valid;
	struct s_so_long	*game;
}				t_mapa;

typedef struct s_window
{
	int	width;
	int	height;
	int	x;
	int	y;
}				t_window;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_images
{
	struct s_img	wall;
	struct s_img	empty_space;
	struct s_img	collectible;
	struct s_img	exit;
	struct s_img	player;	
}				t_images;

typedef struct s_so_long
{
	void			*mlx;
	void			*window;
	struct s_mapa	mapa;
	struct s_window	ventana;
	struct s_images	imagenes;
}				t_so_long;

void	ft_error(size_t value);
size_t	ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_check_args(int argc, char **argv);
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