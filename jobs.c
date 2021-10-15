#include "philosopher.h"

void            ft_delay(int delay)
{

}

void            ft_output(t_philo *philo, char *msg)
{
    size_t current_time;

    current_time = ft_time() - table->timeof_start;
    pthread_mutex_lock(&table->display_msg);
    printf("--[%ld]s-- I'm Philo [%d] and [%s)]\n", current_time, philo->id, msg);
    if (ft_strncmp(msg, "dead", 4) == 0)
        exit(0);
    pthread_mutex_unlock(&table->display_msg);
}

void        ft_grab_forks(t_philo *philo)
{
    pthread_mutex_lock(&table->forks[philo->left_fork]);
    ft_output(philo, "I took the left fork");
    pthread_mutex_lock(&table->forks[philo->right_fork]);
    ft_output(philo, "I took the right fork");
}

void        ft_start_eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->dontdisturb);
    ft_output(philo, "I am eating");
    philo->last_meal = ft_time();
    philo->nb_meals += 1;
    pthread_mutex_unlock(&philo->dontdisturb);
}

void        ft_release_forks(t_philo *philo)
{
    pthread_mutex_unlock(&table->forks[philo->left_fork]);
    ft_output(philo, "I released the left fork");
    pthread_mutex_unlock(&table->forks[philo->right_fork]);
    ft_output(philo, "I released the right fork");
}

