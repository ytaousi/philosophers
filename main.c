/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:43:31 by ytaousi           #+#    #+#             */
/*   Updated: 2021/10/18 20:12:54 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*job(void *philos)
{
	t_philo	*philo;
	size_t	last_meal;

	philo = philos;
	last_meal = ft_time();
	while (1)
	{
		ft_grab_forks(philo);
		ft_start_eating(philo);
		ft_release_forks(philo);
		display(philo, "let's takee a snap noww");
		ft_delaysleep();
		display(philo, "nice naaap letss think");
	}
}

int	ft_damnnorm(int ac)
{
	size_t	last_meal;
	int		i;

	while (1)
	{
		i = 0;
		while (i < g_table->info->nb_philos)
		{
			last_meal = g_table->philo[i].last_meal;
			if ((ft_time() - last_meal) >= g_table->info->time_to_die)
			{
				if (display(g_table->philo, "Dead") == 0)
					return (0);
			}
			if ((ac == 6 && g_table->info->nb_timeof_eat == 0) \
					|| g_table->meal_count == g_table->info->nb_philos)
				return (0);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	g_table = (t_table *)malloc(sizeof(t_table));
	if (!g_table)
		return (0);
	g_table->meal_count = 0;
	if (ac == 5 || ac == 6)
	{
		g_table->info = ft_parsedata(ac, av);
		if (!g_table->info)
			return (0);
		g_table->philo = ft_init_philosophers();
		g_table->forks = ft_init_forks();
		ft_create_threads();
		if (ft_damnnorm(ac) == 0)
			return (0);
	}
	else
	{
		printf("Error nb args\n");
		return (0);
	}
	return (0);
}
