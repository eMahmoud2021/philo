/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_routine_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:00:35 by memam             #+#    #+#             */
/*   Updated: 2022/08/13 08:37:59 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int     ft_init_processes(t_philo *philo)
{
    int     num;
    int     i;

    num = philo->data->philo_num;
    i = -1;
    philo->data->start = get_time();
    while (++i < num)
    {
        philo[i].process_id = fork();
        if (philo[i].process_id == -1)
        {
            write(2, "fork error !\n", 14);
            return (1);
        }
        if (philo[i].process_id == 0)
        {
            if (philo[i].id % 2 == 0)
                usleep(500);
            ft_philo_routine(&philo[i]);
            exit(EXIT_SUCCESS);
        }
    }
    return (0);
}

void    *ft_thread(void *args)
{
    t_philo *philo;

    philo =(t_philo *)args;
    philo->last_eat = get_time();
    while (1)
    {
        if (get_time() - philo->last_eat >= philo->data->time_to_die)
        {
            ft_print_msg(philo, 5);
            exit(1);
        }
        if (philo->data->num_meals > 0 && philo->is_put == 1
                && philo->eaten_meals >= philo->data->num_meals)
                exit(0);
        usleep(90);
    }
    return (NULL);
}

void    ft_philo_routine(t_philo *philo)
{
    philo->last_eat = get_time();
    pthread_create(&philo->thread, NULL, &ft_thread, (void *)philo);
    while (1)
    {
        ft_take_forks(philo);
        ft_put_forks(philo);
        ft_print_msg(philo, 4);
    }   
}

void    ft_take_forks(t_philo *philo)
{
    sem_wait(philo->data->forks);
    ft_print_msg(philo, 1);
    sem_wait(philo->data->forks);
    philo->is_put = 0;
    ft_print_msg(philo, 11);
    ft_print_msg(philo, 2);
    ft_sleep(philo->data->time_to_eat);
    philo->last_eat = get_time();
}

void    ft_put_forks(t_philo *philo)
{
    sem_post(philo->data->forks);
    sem_post(philo->data->forks);
    philo->is_put = 1;
    ft_print_msg(philo, 3);
    ft_sleep(philo->data->time_to_sleep);
}