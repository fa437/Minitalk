/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:42:32 by fasare            #+#    #+#             */
/*   Updated: 2023/09/17 19:46:46 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/* ----------------server----------------*/
void	ft_signal_handler(int signal, siginfo_t *info, void *context);

/* ---------------client------------------*/
void	acknowledgement(int signal);
void	ft_send_binary_data(int pid, char c);

#endif
