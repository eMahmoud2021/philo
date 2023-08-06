/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:48:28 by memam             #+#    #+#             */
/*   Updated: 2022/08/12 19:36:52 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	ft_isdigit(int nbr)
{
	if (nbr >= '0' && nbr <= '9')
		return (1);
	return (0);
}

unsigned int get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(int t_t_sleep)
{
	unsigned int time;

	time = get_time() + t_t_sleep;
	while (get_time() < time)
		usleep(200);
}

void	ft_print_msg(t_philo *philo, int option)
{
	pthread_mutex_lock(&philo->data->message);
	printf("%u ", get_time() - philo->data->start);
	if (option == 1)
		printf("%d has taken a right_fork\n", philo->id);
	else if (option == 11)
		printf("%d has taken a left_fork\n", philo->id);
	else if (option == 2)
	{
		printf("%d is eating\n", philo->id);
		pthread_mutex_lock(&philo->mutex);
		philo->state = 2;
		philo->last_eat = get_time();
		philo->eaten_meals++;
		pthread_mutex_unlock(&philo->mutex);
	}
	else if (option == 3)
	{
		printf("%d is sleeping\n", philo->id);
		pthread_mutex_lock(&philo->mutex);
		philo->state = 0;
		pthread_mutex_unlock(&philo->mutex);
	}
	else if (option == 4)
		printf("%d is thinking\n", philo->id);
	else
	{
		ft_print_msg2(option, philo);
		return ;
	}
	pthread_mutex_unlock(&philo->data->message);
}