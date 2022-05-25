/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:55:59 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/02 09:28:15 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define FAILURE 1
# define ERROR 2
# define ERROR2 3

/*********************************/
/*       L I B R A R I E S       */
/*********************************/

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <time.h>

/*********************************/
/*      S T R U C T U R E S      */
/*********************************/

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct s_philo
{
	int				id_philo;
	long long		last_meal;
	int				tt_die;
	int				nb_philo;
	int				tt_eat;
	int				tt_sleep;
	int				eat_round;
	int				eat_count;
	int				l_fk;
	int				r_fk;
	pthread_t		philo;
	pthread_mutex_t	lock1;
	pthread_mutex_t	lock2;
	t_data			*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				is_over;
	int				is_dead;
	int				eat_round;
	int				belly;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock0;
	pthread_mutex_t	print;
	t_philo			*philo;
}					t_data;

typedef struct s_stuff
{
	int				id_philo;
	long long		last_meal;
	int				tt_die;
}			t_stuff;

/*********************************/
/*       F U N C T I O N S       */
/*********************************/

/*-------- P A R S I N G --------*/

int			int_size_error(char *av);
int			len_error_etc(int ac, char **av);
int			not_digit(char *av);
int			not_zero_or_neg(char *av);
int			parsing(int ac, char **av);

/*----------- I N I T -----------*/

int			get_space(t_data *data);
int			mutex_init(t_data *data);
int			fill_data(char **av, t_data *data);

void		init_struct(t_data *data);
void		init_philo(t_data *data);
void		print_struct(t_data *data);

/*-------- R O U T I N E --------*/

int			launch_thread(t_data *data);
int			is_finished(t_data *data);

void		is_eating(t_philo *philo, t_data *data);
void		is_sleeping(t_philo *philo, t_data *data);
void		routine_one_philo(t_data *data);

void		*routine(void *arg);

/*------------ E N D ------------*/

int			is_over(t_data *data);

void		kill_philo(t_philo *philo);
void		check_to_kill(t_data *data);
void		belly_is_full(t_data *data);

/*----------- T I M E -----------*/

long long	ft_gettime(void);
long long	display_time(t_data *data);

void		ft_usleep(t_data *data, long long time);

/*--------- V I S U A L ---------*/

void		display(t_philo *philo, char *str);
void		display_death(t_philo *philo, char *str);

/*---------- U T I L S ----------*/

int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_strlen(const char *s);

long		ft_atol(const char *str);

void		ft_putstr_fd(char *s, int fd);

/*---------- C L E A N ----------*/

int			destroy_mutex(t_data *data);

#endif
