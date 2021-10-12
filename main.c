#include "philosopher.h"

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

int main(int ac, char **av)
{
    t_table *table;
    t_philo *philosophers;

    table = (t_table *)malloc(sizeof(t_table));
    if (ac == 5 || ac == 6)
    {
        table->info = ft_parsedata(ac, av);
        if (!table->info)
            exit(0);
        //printf("number of philos :[%d]\ntime_to_die :[%lf]\ntime_to_eat :[%lf]\ntime_to_sleep :[%lf]\nnumber_of_times_philos_eat :[%d]\n", parameters->nb_philos, parameters->time_to_die, parameters->time_to_eat, parameters->time_to_sleep, parameters->nb_timeof_eat);
    }
    else
    {
        printf("Error nb args\n");
    }
    return (0);
}