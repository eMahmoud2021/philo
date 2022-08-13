/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:59:40 by memam             #+#    #+#             */
/*   Updated: 2022/08/12 17:34:14 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_struct(int ac, char **av, t_args *args)
{
    args->philo_num = ft_atoi(av[1]);
    args->time_to_die = ft_atoi(av[2]);
    args->time_to_eat = ft_atoi(av[3]);
    args->time_to_sleep = ft_atoi(av[4]);
    args->num_meals = 0;
    args->start =get_time();
    if (ac == 6)
        args->num_meals = ft_atoi(av[5]);
    args->forks = malloc(sizeof(pthread_mutex_t) * args->philo_num);
    if (args->forks == NULL)
    {
        write(2, "Malloc error !\n", 16);
        return (1);
    }
    if (pthread_mutex_init(&args->message, NULL) != 0)
    {
        write(2, "pthread_mutex_ini error !\n", 27);
        return (1);
    }
    return (0);
}

t_philo *init_philo_struct(t_args *args)
{
    int i;
    t_philo *philo;

    philo = malloc(sizeof(t_philo) * args->philo_num);
    if (philo == NULL)
    {
        write(2, "Malloc error !\n", 16);
        return (NULL);
    }
    i = -1;
    while (++i < args->philo_num)
    {
        philo[i].id = i + 1;
        philo[i].left_fork = (i + 1) % args->philo_num;
        philo[i].right_fork = i;
        philo[i].last_eat = get_time();
        philo[i].eaten_meals = 0;
        philo[i].data = args;
        if (pthread_mutex_init(&args->forks[i], NULL) != 0
                    || pthread_mutex_init(&philo->mutex, NULL) != 0)
        {
            write(2, "pthread_mutex_ini error !\n", 27);
            return (NULL);
        }
    }
    return (philo);
}