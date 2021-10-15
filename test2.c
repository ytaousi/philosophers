# include "philosopher.h"

int main(int ac , char **av)
{
    size_t time_start = ft_time();
    size_t current_time;
    if (ac || av)
    {
        ;
    }
    
    while (1)
    {
        current_time = ft_time() - time_start;
        printf("---[%ld]ms\n", current_time);
        usleep(800);
    }
    return (0);
}