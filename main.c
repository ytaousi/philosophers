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

t_philo *ft_init_philosophers()
{
    t_philo *philosophers;
    int     i;

    i = 0;
    philosophers = (t_philo *)malloc(sizeof(t_philo) * table->info->nb_philos);
    if (!philosophers)
    {
        printf("Error create philo struct\n");
        return (NULL);
    }
    while (i < table->info->nb_philos)
    {
        philosophers[i].id = i + 1;
        philosophers[i].nb_meals = 0;
        philosophers[i].last_meal = ft_time();
        philosophers[i].left_fork = i;
        philosophers[i].right_fork = (i + 1) % table->info->nb_philos;
        i++;
    }
    return (philosophers);
}

pthread_mutex_t *ft_init_forks()
{
    pthread_mutex_t *forks;
    int             i;

    i = 0;
    forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->info->nb_philos);
    if (!forks)
    {
        printf("error creating a mutex\n");
        return (NULL);
    }
    while (i < table->info->nb_philos)
    {
        pthread_mutex_init(&(forks[i]), NULL);
        i++;
    }
    pthread_mutex_init(&table->display_msg, NULL);
    return (forks);
}

void    *job(void *philos)
{
    t_philo *philo;
    size_t  current_time;

    philo = philos;
    while (1)
    {
        current_time = ft_time() - table->timeof_start;
        pthread_mutex_lock(&table->forks[philo->left_fork]);
        pthread_mutex_lock(&table->display_msg);
        printf("[%ld]s--philo->[%d] took left fork [%d] loooockedd  \n", current_time, philo->id, philo->left_fork);
        pthread_mutex_unlock(&table->display_msg);
        pthread_mutex_lock(&table->forks[philo->right_fork]);
        pthread_mutex_lock(&table->display_msg);
        printf("[%ld]s--philo ->[%d] took right fork [%d] loooockedd \n", current_time, philo->id, philo->right_fork);
        pthread_mutex_unlock(&table->display_msg);
        pthread_mutex_lock(&table->display_msg);
        printf("[%ld]s--philo->[%d]<-->im eating....\n", current_time, philo->id);
        printf("[%ld]s--philo->[%d]<-->im sleeping....\n", current_time, philo->id);
        printf("[%ld]s--philo->[%d]<-->im thinking....\n", current_time, philo->id);
        pthread_mutex_unlock(&table->display_msg);
        pthread_mutex_unlock(&table->forks[philo->left_fork]);
        pthread_mutex_unlock(&table->forks[philo->right_fork]);
    }
}

void    ft_create_threads()
{
    pthread_t   *philo_threads;
    int         i;

    i = 0;
    philo_threads = (pthread_t *)malloc(sizeof(pthread_t) * table->info->nb_philos);
    table->timeof_start = ft_time();
    while (i < table->info->nb_philos)
    {
        pthread_create(philo_threads + i, NULL, &job, &table->philo[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    table = (t_table *)malloc(sizeof(t_table));
    if (ac == 5 || ac == 6)
    {
        table->info = ft_parsedata(ac, av);
        //table_info(table);
        if (!table->info)
            exit(0);
        // Initialise table of philo's attribute
        table->philo = ft_init_philosophers();
        //philo_info(table);
        // Initialise fork's every fork is a mutex
        table->forks = ft_init_forks();
        ft_create_threads();
        // Initialise supervisor to monitor threads
        while (1);
    }
    else
    {
        printf("Error nb args\n");
        return (0);
    }
    return (0);
}