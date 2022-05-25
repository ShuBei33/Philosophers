/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:35:06 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/02 07:48:19 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].philo, NULL) != 0)
			return (ft_putstr_fd("pthread join failed\n", 2), ERROR);
		pthread_mutex_destroy(&(data->philo[i].lock1));
		pthread_mutex_destroy(&(data->philo[i].lock2));
	}
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->fork[i]));
	pthread_mutex_destroy(&(data->lock0));
	pthread_mutex_destroy(&(data->print));
	free(data->philo);
	free(data->fork);
	return (SUCCESS);
}
