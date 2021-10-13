#ifndef _PHILOSOPHERS_H
# define _PHILOSOPHERS_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct      s_info
{
    int             nb_philos;
    double          time_to_die;
    double          time_to_eat;
    double          time_to_sleep;
    int             nb_timeof_eat;
}                   t_info;

typedef struct      s_philo
{
    int             id;
    int             right_fork;
    int             left_fork;
    int             nb_meals;
    double          last_meal;
    pthread_mutex_t role_meal;
}                   t_philo;

typedef struct      s_table
{
    t_info          *info;
    t_philo         *philo;
    pthread_mutex_t *forks;
    size_t          timeof_start;
    pthread_mutex_t display_msg;
}                   t_table;

t_table             *table;

#endif