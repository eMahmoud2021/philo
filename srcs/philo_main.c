/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:58:14 by memam             #+#    #+#             */
/*   Updated: 2022/08/12 19:18:28 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_check_death(t_philo *philo)
{
    int     i;
    i = 0;
    while (i < philo[0].data->philo_num)
    {
        pthread_mutex_lock(&philo[i].mutex);
        if (philo[i].last_eat > 0
                && get_time() - philo[i].last_eat
                >= philo[i].data->time_to_die && philo[i].state != 2)
        {
            ft_print_msg(&philo[i], 5);
            return (1);
        }
        pthread_mutex_unlock(&philo[i].mutex);
        i++;
    }
    return (0);
}

int     ft_check_meals(t_philo *philo)
{
    int i;
    int  count;

    i = 0;
    count = 0;
    while (i < philo[0].data->philo_num)
    {
        pthread_mutex_lock(&philo[i].mutex);
        if (philo[i].eaten_meals >= philo[i].data->num_meals)
            count++;
        pthread_mutex_unlock(&philo[i].mutex);
        i++;
    }
    if (count == philo[0].data->philo_num)
    {
        ft_print_msg(philo, 6);
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    t_args  *args;
    t_philo *philo;

    if (check_args(ac, av))
        return (0);
    args = malloc(sizeof(t_args));
    if (args == NULL)
        return (0);
    if (init_struct(ac, av, args))
        return (0);
    philo = init_philo_struct(args);
    if (philo == NULL)
        return (0);
    if (ft_thr(philo))
        return (0);
    return (0);
}
