#ifndef _PHILOSOPHERS_H
# define _PHILOSOPHERS_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct  s_info
{
    int         nb_philos;
    double      time_to_die;
    double      time_to_eat;
    double      time_to_sleep;
    int         nb_timeof_eat;  
}               t_info;

typedef struct  s_table
{
    t_info  *info;
    t_philo *philo;
}               t_table;

double ft_time(void);



#endif