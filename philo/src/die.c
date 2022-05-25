/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:47:39 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/02 10:19:41 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_over(t_data *data)
{
	int	tmp;

	pthread_mutex_lock(&(data->lock0));
	tmp = data->is_over;
	pthread_mutex_unlock(&(data->lock0));
	return (tmp);
}

void	belly_is_full(t_data *data)
{
	pthread_mutex_lock(&(data->lock0));
	data->belly++;
	if (data->belly >= data->nb_philo)
		data->is_over = SUCCESS;
	pthread_mutex_unlock(&(data->lock0));
}

void	kill_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->lock0));
	philo->data->is_over = SUCCESS;
	philo->data->is_dead = SUCCESS;
	pthread_mutex_unlock(&(philo->data->lock0));
	display_death(philo, "is dead");
}

void	check_to_kill(t_data *data)
{
	int		i;
	t_stuff	c_philo;

	i = 0;
	while (is_over(data) == FAILURE)
	{
		pthread_mutex_lock(&data->philo[i].lock2);
		c_philo = *((t_stuff *)(data->philo + i));
		pthread_mutex_unlock(&data->philo[i].lock2);
		if (ft_gettime() > (c_philo.last_meal + c_philo.tt_die))
			kill_philo(data->philo);
		if (++i >= data->nb_philo)
		{
			i = 0;
			usleep(100);
		}
	}
}
