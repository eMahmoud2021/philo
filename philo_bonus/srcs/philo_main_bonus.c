/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:58:14 by memam             #+#    #+#             */
/*   Updated: 2022/08/13 08:23:35 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void    wait_processes(t_philo *philo)
{
    int     i;
    int     stat;
    int     t;

    i = -1;
    t = -1;
    while (++i < philo[0].data->philo_num)
    {
        waitpid(-1, &stat, 0);
        if (stat != 0)
        {
            while (++t < philo[0].data->philo_num)
                kill(philo[i].process_id, SIGINT);
            return ;
        }
    }
    ft_print_msg(&philo[0], 6);
    return ;
}

int main(int ac, char **av)
{
    t_args  *args;
    t_philo *philo;

    if (check_args(ac, av))
        return (1);
    args = init_parameters(ac, av);
    if (args == NULL)
        return (1);
    philo = init_philo(args);
    if (philo == NULL)
        return (1);
    if (ft_init_processes(philo))
        return (1);
    wait_processes(philo);
}
