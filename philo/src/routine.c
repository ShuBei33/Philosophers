/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:05:20 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/02 12:21:39 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_one_philo(t_data *data)
{
	data->start_time = ft_gettime();
	printf("%lld	philo 1 has taken a fork\n", display_time(data));
	usleep(data->tt_die * 500);
	usleep(data->tt_die * 500);
	printf("%lld	philo 1 is dead\n", display_time(data));
	free(data->philo);
	free(data->fork);
}

void	is_eating(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->fork[philo->l_fk]));
	display(philo, "has taken a fork");
	pthread_mutex_lock(&(data->fork[philo->r_fk]));
	display(philo, "has taken a fork");
	pthread_mutex_lock(&philo->lock2);
	philo->last_meal = ft_gettime();
	pthread_mutex_unlock(&philo->lock2);
	display(philo, "is eating");
	pthread_mutex_lock(&philo->lock1);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->lock1);
	ft_usleep(data, data->tt_eat);
	pthread_mutex_unlock(&(data->fork[philo->l_fk]));
	pthread_mutex_unlock(&(data->fork[philo->r_fk]));
	pthread_mutex_lock(&philo->lock1);
	if (data->eat_round > 0 && (philo->eat_count == data->eat_round))
		belly_is_full(data);
	pthread_mutex_unlock(&philo->lock1);
}

void	is_sleeping(t_philo *philo, t_data *data)
{
	display(philo, "is sleeping");
	ft_usleep(data, data->tt_sleep);
	display(philo, "is thinking");
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&data->lock0);
	pthread_mutex_unlock(&data->lock0);
	if (philo->id_philo % 2)
		usleep(200);
	while (is_over(data) == FAILURE)
	{
		is_eating(philo, data);
		is_sleeping(philo, data);
	}
	return (SUCCESS);
}
