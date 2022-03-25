/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:26:57 by aleferra          #+#    #+#             */
/*   Updated: 2022/03/25 13:59:23 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb = nb + 48;
		write(1, &nb, 1);
	}
}

void	ft_putstr(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
		write(1, &str[index], 1);
}

void	ft_put_message(t_philosopher *philo, int message)
{
	int		actu_time;

	pthread_mutex_lock(&philo->deadischeck);
	if (philo->dead == TRUE)
	{
		pthread_mutex_unlock(&philo->deadischeck);
		return ;
	}
	pthread_mutex_unlock(&philo->deadischeck);
	actu_time = ft_time() - philo->info.time_to_start;
	if (message == THINK)
		printf("%d %d is thinking\n", actu_time, philo->id);
	else if (message == SLEEP)
		printf("%d %d is sleeping\n", actu_time, philo->id);
	else if (message == FORK)
		printf("%d %d has taken a fork\n",
			actu_time, philo->id);
	else if (message == EAT)
		printf("%d %d is eating\n", actu_time, philo->id);
}

long long int	ft_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_smart_usleep(int time, int nb_philo)
{
	long long int	rules;
	long long int	start;

	rules = (long long int) time;
	start = ft_time();
	usleep(rules / 2 * 1000);
	while (ft_time() - start < rules)
	{
		if (nb_philo > 50)
			usleep(500);
		else
			usleep(50);
	}
}
