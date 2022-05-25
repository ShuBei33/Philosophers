/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:37:33 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/03 20:41:47 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	start_philo(t_data *data, char **av)
{
	if (fill_data(av, data) == ERROR)
		return (ERROR);
	if (data->nb_philo == 1)
	{
		routine_one_philo(data);
		return (SUCCESS);
	}
	else
	{
		mutex_init(data);
		if (launch_thread(data) == ERROR)
			return (destroy_mutex(data), ERROR);
	}
	if (data->is_dead != SUCCESS)
		printf("All bellies are full !\n");
	return (1);
}

int	fill_data(char **av, t_data *data)
{
	data->nb_philo = ft_atol(av[1]);
	data->tt_die = ft_atol(av[2]);
	data->tt_eat = ft_atol(av[3]);
	data->tt_sleep = ft_atol(av[4]);
	if (av[5])
		data->eat_round = ft_atol(av[5]);
	if (get_space(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void	init_struct(t_data *data)
{
	data->fork = NULL;
	data->nb_philo = 0;
	data->tt_die = 0;
	data->tt_eat = 0;
	data->tt_sleep = 0;
	data->eat_round = 0;
	data->is_over = 1;
	data->is_dead = 1;
	data->belly = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	init_struct(&data);
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (parsing(ac, av) != 0)
		return (EXIT_FAILURE);
	if (start_philo(&data, av) != 1)
		return (SUCCESS);
	destroy_mutex(&data);
	return (0);
}
