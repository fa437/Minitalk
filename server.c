/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:25:44 by fasare            #+#    #+#             */
/*   Updated: 2023/09/18 15:40:42 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	data;
	char		c;

	(void)context;
	if (signal == SIGUSR1)
		data |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (data == 0)
		{
			kill(info->si_pid, SIGUSR2);
			data = 0;
			write(1, "\n", 1);
			return ;
		}
		c = data;
		write (1, &c, 1);
		data = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	signal;

	pid = getpid();
	ft_putstr_fd("PID is ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal.sa_sigaction = ft_signal_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
