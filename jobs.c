/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:56 by ytaousi           #+#    #+#             */
/*   Updated: 2021/10/18 17:44:30 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_delaysleep(void)
{
	size_t	delay;
	size_t	beginning;

	beginning = ft_time();
	delay = g_table->info->time_to_sleep;
	while ((ft_time() - beginning) < delay)
		usleep(60);
}

void	ft_delaymeal(void)
{
	size_t	delay;
	size_t	beginning;

	beginning = ft_time();
	delay = g_table->info->time_to_eat;
	while ((ft_time() - beginning) < delay)
		usleep(60);
}

void	ft_grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&g_table->forks[philo->left_fork]);
	display(philo, "I took the left fork");
	pthread_mutex_lock(&g_table->forks[philo->right_fork]);
	display(philo, "I took the right fork");
}

void	ft_start_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->dontdisturb);
	display(philo, "I am eating");
	ft_delaymeal();
	philo->nb_meals++;
	if (philo->nb_meals == g_table->info->nb_timeof_eat)
		g_table->meal_count++;
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->dontdisturb);
}

void	ft_release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&g_table->forks[philo->left_fork]);
	display(philo, "I released the left fork");
	pthread_mutex_unlock(&g_table->forks[philo->right_fork]);
	display(philo, "I released the right fork");
}
