/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memam <memam@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:18:02 by memam             #+#    #+#             */
/*   Updated: 2022/08/12 21:38:26 by memam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	check_args(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (check_empty(ac, av))
			return (1);
		else if (check_numbr(ac, av))
			return (1);
		else if (ft_atoi(av[1]) == 0)
		{
			write(2, " N of philos mast be greater then 0 !\n", 39);
			return (1);
		}
	}
	else
	{
		write(2, "Wrong : Please Check Arguments !\n", 34);
		return (1);
	}
	return (0);
}

int	check_empty(int ac, char **av)
{
	if (av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0'
		|| av[4][0] == '\0' || (ac == 6 && av[5][0] == '\0'))
	{
		write(2, "Wrong : Empty Arguments !\n", 27);
		return (1);
	}
	return (0);
}

int	check_numbr(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				write(2, "Wrong : Please Put Only digit !\n", 33);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print_msg2(int option, t_philo *philo)
{
	if (option == 5)
		printf("%d died\n", philo->id);
	else if (option == 6)
		printf("end\n");
}
