/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:59:40 by memam             #+#    #+#             */
/*   Updated: 2022/08/13 08:23:39 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

t_args	*init_parameters(int ac, char **av)
{
    t_args *args;

    args = malloc(sizeof(t_args));
    if (!args)
    {
        write(2, "Malloc error !\n", 16);
        return (0);
    }
    args->philo_num = ft_atoi(av[1]);
    args->time_to_die = ft_atoi(av[2]);
    args->time_to_eat = ft_atoi(av[3]);
    args->time_to_sleep = ft_atoi(av[4]);
    args->num_meals = 0;
    args->start =get_time();
    if (ac == 6)
        args->num_meals = ft_atoi(av[5]);
    sem_unlink("/sem");
    sem_unlink("/print");
    args->forks = sem_open("/sem", O_CREAT, 0644, args->philo_num);
    args->message = sem_open("/print", O_CREAT, 0644, 1);
    return (args);
}

t_philo *init_philo(t_args *args)
{
    int i;
    t_philo *philo;

    philo = malloc(sizeof(t_philo) * args->philo_num);
    if (philo == NULL)
    {
        return (NULL);
    }
    i = -1;
    while (++i < args->philo_num)
    {
        philo[i].id = i + 1;
        philo[i].last_eat = 0;
        philo[i].eaten_meals = 0;
        philo[i].data = args;
        philo[i].is_put = 1;
    }
    return (philo);
}