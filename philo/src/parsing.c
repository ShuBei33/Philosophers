/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:15:56 by estoffel          #+#    #+#             */
/*   Updated: 2022/04/29 18:51:36 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	not_digit(char *av)
{
	int	i;

	i = 0;
	while (av[i] == ' ')
		++i;
	if (av[i] == '+')
		++i;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

int	not_zero_or_neg(char *av)
{
	int	nb;

	if (av[0] == '-')
		return (ERROR);
	nb = ft_atol(av);
	if (nb == 0)
		return (ERROR);
	return (SUCCESS);
}

int	int_size_error(char *av)
{
	long	nbr;

	nbr = ft_atol(av);
	if (nbr > INT_MAX)
		return (ERROR);
	return (SUCCESS);
}

int	len_error_etc(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (not_digit(av[i]) != 0 || int_size_error(av[i]) != 0
			|| not_zero_or_neg(av[i]) != 0)
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

int	parsing(int ac, char **av)
{
	if (len_error_etc(ac, av) != 0)
		return (ft_putstr_fd("Invalid type of arguments\n", 2), ERROR);
	return (SUCCESS);
}
