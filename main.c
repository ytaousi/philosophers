#include "philosopher.h"

void    *job(void *philos)
{
    t_philo *philo;

    philo = philos;
    while (1)
    {
        ft_grab_forks(philo);
        ft_start_eating(philo);
        ft_release_forks(philo);
        ft_output(philo, "let's takee a snap noww");
        ft_output(philo, "nice naaap letss think");
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
        // better use pthread_join -- initialize supervisor to monitor threads
        int i;
        int time_since_last_meal;
        while(1)
        {
            i = 0;
            while (i < table->info->nb_philos)
            {
                time_since_last_meal = ft_time() - table->timeof_start;
                if (time_since_last_meal >= table->info->time_to_die)
                {
                    ft_output(table->philo, "dead");
                    break;
                }
                i++;
            }
        }
    }
    else
    {
        printf("Error nb args\n");
        return (0);
    }
    return (0);
}