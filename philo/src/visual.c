/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:36:11 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/03 20:56:39 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	display(t_philo *philo, char *str)
{
	const int	id = philo->id_philo;

	if (is_over(philo->data) == FAILURE)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lld	philo %d %s\n", display_time(philo->data), id, str);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void	display_death(t_philo *philo, char *str)
{
	const int	id = philo->id_philo;

	pthread_mutex_lock(&philo->data->print);
	printf("%lld	philo %d %s\n", display_time(philo->data), id, str);
	pthread_mutex_unlock(&philo->data->print);
}
