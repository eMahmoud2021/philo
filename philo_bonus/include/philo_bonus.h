/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:21:05 by memam             #+#    #+#             */
/*   Updated: 2022/08/13 00:25:59 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_args
{
    int             philo_num;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             num_meals;
    int             start; 
    sem_t           *forks;
    sem_t           *message;
}					t_args;

typedef struct s_philo
{
    int             id;
    long            last_eat;
    int             eaten_meals;
    int             is_put;
    pthread_t       thread;
    pid_t           process_id;
    t_args          *data;
	
}					t_philo;

void    wait_processes(t_philo *philo);
/*****************
                    check _error
					             ************************/
int				check_args(int ac, char **av);
int				check_empty(int ac, char **av);
int				check_numbr(int ac, char **av);
void	        ft_print_msg2(int option, t_philo *philo);

/*****************
                    philo _utils
					             ************************/
int				ft_atoi(char *str);
int				ft_isdigit(int nbr);
unsigned int 	get_time(void);
void	        ft_sleep(int t_t_sleep);
void	        ft_print_msg(t_philo *philo, int option);



/*****************
                    thread_routine
					             ************************/
int             ft_init_processes(t_philo *philo);
void            *ft_thread(void *args);
void            ft_philo_routine(t_philo *philo);
void            ft_take_forks(t_philo *philo);
void            ft_put_forks(t_philo *philo);

/*****************
                    init_structures
					             ************************/
t_args	*init_parameters(int ac, char **av);
t_philo         *init_philo(t_args *args);


#endif
