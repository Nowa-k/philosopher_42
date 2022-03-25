/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:21:08 by aleferra          #+#    #+#             */
/*   Updated: 2022/03/25 15:21:33 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_wait_pair(t_philosopher *philo)
{
	if (philo->id % 2 == 1)
		usleep(0.9 * (philo->info.time_to_eat * 1000));
}

void	ft_take_fork(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->info.forks[philo->left_fork]);
	pthread_mutex_lock(&philo->info.forks[philo->right_fork]);
	pthread_mutex_lock(&philo->nocrash);
	philo->last_meal = ft_time() - philo->info.time_to_start;
	pthread_mutex_unlock(&philo->nocrash);
	ft_put_message(philo, FORK);
	ft_put_message(philo, FORK);
	ft_put_message(philo, EAT);
	ft_smart_usleep(philo->info.time_to_eat, philo->info.number_of_philosophers);
	pthread_mutex_unlock(&philo->info.forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info.forks[philo->right_fork]);
	pthread_mutex_lock(&philo->lastmealcheck);
	if (philo->info.number_of_times_each_philosopher_must_eat != -1)
		philo->number_of_eat++;
	pthread_mutex_unlock(&philo->lastmealcheck);
}

void	ft_sleep(t_philosopher *philo)
{
	ft_put_message(philo, SLEEP);
	ft_smart_usleep(philo->info.time_to_sleep, philo->info.number_of_philosophers);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) arg;
	ft_put_message(philo, THINK);
	if (philo->info.number_of_philosophers == 1)
		ft_put_message(philo, FORK);
	ft_wait_pair(philo);
	while (1 && philo->info.number_of_philosophers != 1)
	{
		ft_take_fork(philo);
		ft_sleep(philo);
		pthread_mutex_lock(&philo->deadischeck);
		if (philo->dead == TRUE)
			break ;
		pthread_mutex_unlock(&philo->deadischeck);
		ft_put_message(philo, THINK);
	}
	pthread_mutex_unlock(&philo->deadischeck);
	return (NULL);
}
