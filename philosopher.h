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
    size_t          time_to_die;
    size_t          time_to_eat;
    size_t          time_to_sleep;
    int             nb_timeof_eat;
}                   t_info;

typedef struct      s_philo
{
    int             id;
    int             is_dead;
    int             right_fork;
    int             left_fork;
    int             nb_meals;
    size_t          last_meal;
    pthread_mutex_t dontdisturb;
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

void            ft_grab_forks(t_philo *philo);
void            ft_start_eating(t_philo *philo);
void            ft_release_forks(t_philo *philo);
void            ft_start_sleeping(t_philo *philo);
t_philo         *ft_init_philosophers();
pthread_mutex_t *ft_init_forks();
void            ft_create_threads();
t_info          *ft_parsedata(int ac, char **av);
int             ft_valid_args(int ac, char **av);
int             ft_number(char *str);
double          ft_time(void);
void            ft_delaysleep(t_philo *philo);
void            ft_delaymeal(t_philo *philo);
void            *job(void *philos);
void            display(t_philo *philo, char *msg);
// util or useless funcs hmmm
void            philo_info();
void            table_info();


#endif