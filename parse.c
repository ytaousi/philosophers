/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:43:16 by ytaousi           #+#    #+#             */
/*   Updated: 2021/10/18 16:57:59 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_number(av[i]))
			return (0);
		i++;
	}
	return (1);
}

t_info	*ft_parsedata(int ac, char **av)
{
	t_info	*tmp;

	if (!ft_valid_args(av))
	{
		printf("Error Reading data\n");
		return (NULL);
	}
	tmp = (t_info *)malloc(sizeof(t_info));
	tmp->nb_philos = ft_atoi(av[1]);
	if (tmp->nb_philos == 0)
		return (0);
	tmp->time_to_die = ft_atoi(av[2]);
	tmp->time_to_eat = ft_atoi(av[3]);
	tmp->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		tmp->nb_timeof_eat = ft_atoi(av[5]);
	else
		tmp->nb_timeof_eat = 0;
	return (tmp);
}
