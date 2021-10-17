#include "philosopher.h"

void    *job(void *philos)
{
    t_philo *philo;

    philo = philos;
    while (1)
    {
        ft_grab_forks(philo);
        ft_start_eating(philo);
        ft_delaymeal(philo);
        ft_release_forks(philo);
        display(philo, "let's takee a snap noww");
        ft_delaysleep(philo);
        display(philo, "nice naaap letss think");
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
            return(0);
        // Initialise table of philo's attribute
        table->philo = ft_init_philosophers();
        //philo_info(table);
        // Initialise fork's every fork is a mutex
        table->forks = ft_init_forks();
        ft_create_threads();
        // better use pthread_join -- initialize supervisor to monitor threads
        int i;
        size_t last_meal;
        while (1)
        {
            i = 0;
            while (i < table->info->nb_philos)
            {
                last_meal = table->philo[i].last_meal;
                if ((ft_time() - last_meal) >= table->info->time_to_die)
                {
                    display(table->philo, " I am Dead");
                    return(0);
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