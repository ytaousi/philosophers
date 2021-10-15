# include "philosopher.h"

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
        pthread_mutex_init(&philosophers[i].dontdisturb, NULL);
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