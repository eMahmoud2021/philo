/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:00:35 by memam             #+#    #+#             */
/*   Updated: 2022/08/12 19:37:06 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int     ft_thr(t_philo *philo)
{
    int     i;

    i = 0;
    while (i < philo->data->philo_num)
    {
        philo[i].state = 0;
        if (pthread_create(&philo[i].thread, NULL, &ft_routine, &philo[i]) != 0)
        {
            write(2, "pthread_create error !\n", 24);
            return (1);

        }
        usleep(100);
        i++;
    }
    while (1)
    {
        if (ft_check_death(philo))
            return (0);
        if (philo[0].data->num_meals > 0 && ft_check_meals(philo))
            return (0);
        usleep(100);
    }
    return (0);
}

void    *ft_routine(void *args)
{
    t_philo *philo;

    philo =(t_philo *)args;
    while (1)
    {
        ft_take_forks(philo);
        ft_sleep(philo->data->time_to_eat);
        ft_put_forks(philo);
    }
    return (NULL);
}

void    ft_take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
    ft_print_msg(philo, 1);
    pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
    ft_print_msg(philo, 11);
    ft_print_msg(philo, 2);
}

void    ft_put_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
    pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
    ft_print_msg(philo, 3);
    ft_sleep(philo->data->time_to_sleep);
    ft_print_msg(philo, 4);
}