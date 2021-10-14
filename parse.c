#include "philosopher.h"

void    table_info()
{
    printf("number of philos :[%d]\ntime_to_die :[%lf]\ntime_to_eat :[%lf]\ntime_to_sleep :[%lf]\nnumber_of_times_philos_eat :[%d]\n", table->info->nb_philos, table->info->time_to_die, table->info->time_to_eat, table->info->time_to_sleep, table->info->nb_timeof_eat);
}

void philo_info()
{
    for (int i = 0; i < table->info->nb_philos; i++)
            printf("philo ID:[%d]\nphilo N meals:[%d]\nphilo left fork[%d]\nphilo right fork[%d]\nphilo last meal[%lf]\n", table->philo[i].id, table->philo[i].nb_meals, table->philo[i].left_fork, table->philo[i].right_fork, table->philo[i].last_meal);
}

double ft_time(void)
{
    struct timeval tv;
    double time_in_milli; 

    gettimeofday(&tv, NULL);
    time_in_milli = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    return (time_in_milli);
}

int     ft_number(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int     ft_valid_args(int ac, char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        if (!ft_number(av[i]))
            return (0);
        i++;
    }
    return (1);
}

t_info *ft_parsedata(int ac, char **av)
{
    t_info *tmp;

    if (!ft_valid_args(ac, av))
    {
        printf("Error Reading data\n");
        return (NULL);
    }
    tmp = (t_info *)malloc(sizeof(t_info));
    tmp->nb_philos = ft_atoi(av[1]);
    tmp->time_to_die = ft_atoi(av[2]);
    tmp->time_to_eat = ft_atoi(av[3]);
    tmp->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        tmp->nb_timeof_eat = ft_atoi(av[5]);
    else
        tmp->nb_timeof_eat = 0;
    return (tmp);
}

void            ft_output(t_philo *philo, char *msg)
{
    size_t current_time;

    current_time = ft_time() - table->timeof_start;
    pthread_mutex_lock(&table->display_msg);
    printf("--[%ld]s-- I'm Philo [%d] and its my turn to print to screen, [%s]\n", current_time, philo->id, msg);
    pthread_mutex_unlock(&table->display_msg);
}