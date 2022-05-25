/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:46:03 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/03 20:40:18 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].id_philo = i + 1;
		data->philo[i].nb_philo = data->nb_philo;
		data->philo[i].tt_die = data->tt_die;
		data->philo[i].tt_eat = data->tt_eat;
		data->philo[i].tt_sleep = data->tt_sleep;
		data->philo[i].eat_round = data->eat_round;
		data->philo[i].eat_count = 0;
		data->philo[i].l_fk = i;
		data->philo[i].r_fk = (i + 1) % data->nb_philo;
		data->philo[i].data = data;
	}
}

int	mutex_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL) != 0)
			return (ft_putstr_fd("mutex init failed\n", 2), ERROR);
		if (pthread_mutex_init(&(data->philo[i].lock1), NULL) != 0)
			return (ft_putstr_fd("mutex init failed\n", 2), ERROR);
		if (pthread_mutex_init(&(data->philo[i].lock2), NULL) != 0)
			return (ft_putstr_fd("mutex init failed\n", 2), ERROR);
	}
	if (pthread_mutex_init(&(data->lock0), NULL) != 0)
		return (ft_putstr_fd("mutex init failed\n", 2), ERROR);
	if (pthread_mutex_init(&(data->print), NULL) != 0)
		return (ft_putstr_fd("mutex init failed\n", 2), ERROR);
	return (SUCCESS);
}

int	get_space(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (ft_putstr_fd("malloc failed\n", 2), ERROR);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (free(data->philo), ft_putstr_fd("malloc failed\n", 2), ERROR);
	return (SUCCESS);
}

int	launch_thread(t_data *data)
{
	int	i;

	i = -1;
	init_philo(data);
	data->start_time = ft_gettime();
	pthread_mutex_lock(&data->lock0);
	while (++i < data->nb_philo)
	{
		data->philo[i].last_meal = data->start_time;
		if (pthread_create(&data->philo[i].philo, NULL,
				&routine, &data->philo[i]) != 0)
		{
			pthread_mutex_unlock(&data->lock0);
			return (perror(""), ERROR);
		}
	}
	pthread_mutex_unlock(&data->lock0);
	check_to_kill(data);
	return (SUCCESS);
}
