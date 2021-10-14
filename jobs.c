#include "philosopher.h"

void        ft_grab_forks(t_philo *philo)
{
    pthread_mutex_lock(&table->forks[philo->left_fork]);
    ft_output(philo, "I took the left fork");
    pthread_mutex_lock(&table->forks[philo->right_fork]);
    ft_output(philo, "I took the right fork");
}

void        ft_start_eating(t_philo *philo)
{
    ft_output(philo, "I am eating");
}

void        ft_release_forks(t_philo *philo)
{
    pthread_mutex_unlock(&table->forks[philo->left_fork]);
    ft_output(philo, "I released the left fork");
    pthread_mutex_unlock(&table->forks[philo->right_fork]);
    ft_output(philo, "I released the right fork");
}

// void     ft_sleep()
// {

// }

// void     ft_think()
// {

// }