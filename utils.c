/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:46:33 by ytaousi           #+#    #+#             */
/*   Updated: 2021/10/18 18:33:59 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	display(t_philo *philo, char *msg)
{
	size_t	current_time;

	current_time = ft_time() - g_table->timeof_start;
	pthread_mutex_lock(&g_table->display_msg);
	printf("[%ld]millisecond Philo [%d] : [%s]\n", current_time, philo->id, msg);
	if (ft_strncmp(msg, "Dead", 4) == 0)
		return (0);
	pthread_mutex_unlock(&g_table->display_msg);
	return (1);
}

double	ft_time(void)
{
	struct timeval	tv;
	double			time_in_milli;

	gettimeofday(&tv, NULL);
	time_in_milli = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time_in_milli);
}
