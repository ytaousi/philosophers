#include "philosopher.h"

double ft_time(void)
{
    struct timeval tv;
    double time_in_milli; 
    
    gettimeofday(&tv, NULL);
    time_in_milli = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    return (time_in_milli);
}

t_info *ft_parsedata(int ac, char **av)
{
    t_info *tmp;

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
    t_info *parameters;

    if (ac == 5 || ac == 6)
    {
        parameters = ft_parsedata(ac, av);
        //printf("number of philos :[%d]\ntime_to_die :[%lf]\ntime_to_eat :[%lf]\ntime_to_sleep :[%lf]\nnumber_of_times_philos_eat :[%d]\n", parameters->nb_philos, parameters->time_to_die, parameters->time_to_eat, parameters->time_to_sleep, parameters->nb_timeof_eat);
    }
    else
    {
        printf("Error nb args\n");
    }
    return (0);
}