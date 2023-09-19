/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:42:15 by fasare            #+#    #+#             */
/*   Updated: 2023/09/18 15:40:42 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	acknowledgement(int signal)
{
	if (signal == SIGUSR2)
		ft_putstr_fd("Message recieved\n", 1);
}

void	ft_send_binary_data(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_binary_data(pid, argv[2][i]);
			i++;
		}
		signal(SIGUSR2, acknowledgement);
		//ft_send_binary_data(pid, '\0');
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 1);
		return (1);
	}
	return (0);
}
