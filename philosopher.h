/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:40:42 by ytaousi           #+#    #+#             */
/*   Updated: 2021/10/18 20:12:49 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int		nb_philos;
	int		nb_timeof_eat;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
}				t_info;

typedef struct s_philo
{
	int				id;
	int				right_fork;
	int				left_fork;
	int				nb_meals;
	size_t			last_meal;
	pthread_mutex_t	dontdisturb;
}				t_philo;

typedef struct s_table
{
	t_info			*info;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	size_t			timeof_start;
	pthread_mutex_t	display_msg;
	int				meal_count;
}				t_table;

t_table				*g_table;

void				ft_grab_forks(t_philo *philo);
void				ft_start_eating(t_philo *philo);
void				ft_release_forks(t_philo *philo);
void				ft_start_sleeping(t_philo *philo);
t_philo				*ft_init_philosophers(void);
pthread_mutex_t		*ft_init_forks(void);
void				ft_create_threads(void);
t_info				*ft_parsedata(int ac, char **av);
int					ft_valid_args(char **av);
int					ft_number(char *str);
double				ft_time(void);
void				ft_delaysleep(void);
void				ft_delaymeal(void);
void				ft_free_table(void);
void				*job(void *philos);
int					display(t_philo *philo, char *msg);
int					ft_isdigit(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);

#endif
