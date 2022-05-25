/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:32:44 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/02 06:27:46 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((((long long) tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}

long long	display_time(t_data *data)
{
	long long	time;

	time = ft_gettime() - data->start_time;
	return (time);
}

void	ft_usleep(t_data *data, long long time)
{
	long long	debut_time;

	debut_time = ft_gettime();
	while (is_over(data) == FAILURE)
	{
		if ((ft_gettime() - debut_time) >= time)
			break ;
		usleep(1000);
	}
}
