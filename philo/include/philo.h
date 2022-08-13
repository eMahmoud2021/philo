/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:21:05 by memam             #+#    #+#             */
/*   Updated: 2022/08/12 19:11:22 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
    int             philo_num;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             num_meals;
    int             start; // si no long int
    pthread_mutex_t *forks;
    pthread_mutex_t message;
}					t_args;

typedef struct s_philo
{
    int             id;
    int             left_fork;
    int             right_fork;
    long            last_eat;
    int             state;
    int             eaten_meals;
    pthread_t       thread;
    pthread_mutex_t mutex;
    t_args          *data;
	
}					t_philo;

int             ft_check_death(t_philo *philo);
int             ft_check_meals(t_philo *philo);

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
int             ft_thr(t_philo *philo);
void            *ft_routine(void *args);
void            ft_take_forks(t_philo *philo);
void            ft_put_forks(t_philo *philo);

/*****************
                    init_structures
					             ************************/
int             init_struct(int ac, char **av, t_args *args);
t_philo         *init_philo_struct(t_args *args);


#endif
