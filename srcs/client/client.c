/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:27:43 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/12 17:20:15 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static int	g_received = -1;

static void	send_sign(pid_t pid, int nb)
{
	if (g_received)
	{
		g_received = 0;
		if (nb == 0)
			if (kill(pid, SIGUSR1) == -1)
				ft_error(RED "ERROR: " RST_CLR "Connection not established.");
		if (nb == 1)
			if (kill(pid, SIGUSR2) == -1)
				ft_error(RED "ERROR: " RST_CLR "Connection not established.");
	}
}

static void	cut_bits(pid_t pid, char to_send)
{
	char	c;
	int		nb;

	c = 0;
	while (c < 8)
	{
		nb = (to_send >> c++) & 1;
		while (1)
		{
			if (g_received)
			{
				send_sign(pid, nb);
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
		ft_putnbr_fd(nb_signals, STDOUT_FILENO);
		ft_putstr_fd(" bits received.\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char const *argv[])
{
	struct sigaction	action;

	action.sa_handler = signal_handler;
	action.sa_flags = SA_RESTART;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_error(RED "ERROR: " RST_CLR "Unable to create handler for SIGUSR1.");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error(RED "ERROR: " RST_CLR "Unable to create handler for SIGUSR2.");
	check_args(argc, argv);
	while (true)
		pause();
	return (0);
}
