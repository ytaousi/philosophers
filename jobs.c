#include "philosopher.h"

void            display(t_philo *philo, char *msg)
{
    size_t current_time;

    current_time = ft_time() - table->timeof_start;
    pthread_mutex_lock(&table->display_msg);
    printf("--[%ld]s-- I'm Philo [%d] and its my turn to print to screen, [%s]\n", current_time, philo->id, msg);
    pthread_mutex_unlock(&table->display_msg);
}

double ft_time(void)
{
    struct timeval tv;
    double time_in_milli; 

    gettimeofday(&tv, NULL);
    time_in_milli = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    return (time_in_milli);
}

void        ft_grab_forks(t_philo *philo)
{
    pthread_mutex_lock(&table->forks[philo->left_fork]);
    display(philo, "I took the left fork");
    pthread_mutex_lock(&table->forks[philo->right_fork]);
    display(philo, "I took the right fork");
}

void        ft_start_eating(t_philo *philo)
{
    display(philo, "I am eating");
    // delay time_to_eat
}

void        ft_release_forks(t_philo *philo)
{
    pthread_mutex_unlock(&table->forks[philo->left_fork]);
    display(philo, "I released the left fork");
    pthread_mutex_unlock(&table->forks[philo->right_fork]);
    display(philo, "I released the right fork");
}
