/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:43:08 by ytaousi           #+#    #+#             */
/*   Updated: 2021/10/18 17:51:57 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_free_table(void)
{
	if (g_table->info)
		free(g_table->info);
	if (g_table->philo)
		free(g_table->philo);
	if (g_table)
		free(g_table);
}

t_philo	*ft_init_philosophers(void)
{
	int		i;
	t_philo	*philosophers;

	i = 0;
	philosophers = (t_philo *)malloc(sizeof(t_philo) \
			* g_table->info->nb_philos);
	if (!philosophers)
	{
		printf("Error create philo struct\n");
		return (NULL);
	}
	while (i < g_table->info->nb_philos)
	{
		philosophers[i].id = i + 1;
		philosophers[i].nb_meals = 0;
		philosophers[i].last_meal = ft_time();
		philosophers[i].left_fork = i;
		philosophers[i].right_fork = (i + 1) % g_table->info->nb_philos;
		pthread_mutex_init(&philosophers[i].dontdisturb, NULL);
		i++;
	}
	return (philosophers);
}

pthread_mutex_t	*ft_init_forks(void)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* g_table->info->nb_philos);
	if (!forks)
	{
		printf("error creating a mutex\n");
		return (NULL);
	}
	while (i < g_table->info->nb_philos)
	{
		pthread_mutex_init(&(forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&g_table->display_msg, NULL);
	return (forks);
}

void	ft_create_threads(void)
{
	int			i;
	pthread_t	*philo_threads;

	i = 0;
	philo_threads = (pthread_t *)malloc(sizeof(pthread_t) \
			* g_table->info->nb_philos);
	g_table->timeof_start = ft_time();
	while (i < g_table->info->nb_philos)
	{
		pthread_create(philo_threads + i, NULL, &job, &g_table->philo[i]);
		i++;
		usleep(60);
	}
}
