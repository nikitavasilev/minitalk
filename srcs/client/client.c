/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:27:43 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/02 05:39:57 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "ansi_colors.h"

static int	g_received = -1;

static void	send_sign(pid_t pid, short bit)
{
	if (bit == 0)
		if (kill(pid, SIGUSR1) == -1)
			ft_error(RED "ERROR: " RST_CLR "Connection not established.");
	if (bit == 1)
		if (kill(pid, SIGUSR2) == -1)
			ft_error(RED "ERROR: " RST_CLR "Connection not established.");
}

static void	cut_bits(pid_t pid, char to_send)
{
	short	i;
	short	bit;

	i = 0;
	while (i < 8)
	{
		bit = (to_send >> i++) & 1;
		while (1)
		{
			if (g_received)
			{
				g_received = 0;
				send_sign(pid, bit);
				break ;
			}
		}
	}
}

void	cut_str(pid_t pid, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		cut_bits(pid, str[i++]);
	cut_bits(pid, 0);
}

static void	signal_handler(int signo)
{
	static size_t	nb_signals = 0;

	if (signo == SIGUSR1)
	{
		g_received = 1;
		++nb_signals;
	}
	else if (signo == SIGUSR2)
	{
		nb_signals -= 7;
		ft_putstr_color_fd(GRN, "\nReceived: ", STDOUT_FILENO);
		ft_putnbr_fd(nb_signals, STDOUT_FILENO);
		ft_putstr_fd(" bits (", STDOUT_FILENO);
		ft_putnbr_fd(nb_signals / 8, STDOUT_FILENO);
		ft_putstr_fd(" bytes)\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char const *argv[])
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	action.sa_handler = signal_handler;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_error(RED "ERROR: " RST_CLR "Unable to create handler for SIGUSR1.");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error(RED "ERROR: " RST_CLR "Unable to create handler for SIGUSR2.");
	check_args(argc, argv);
	while (1)
		pause();
	return (0);
}
