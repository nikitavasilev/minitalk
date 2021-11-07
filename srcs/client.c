/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:27:43 by nvasilev          #+#    #+#             */
/*   Updated: 2021/11/07 18:01:52 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_nb_signals = 0;

static void	send_sign(pid_t pid, int nb)
{
	if (nb == 0)
		if (kill(pid, SIGUSR1) == -1)
			ft_error(RED "ERROR: " RST_CLR "Connection not established.");
	if (nb == 1)
		if (kill(pid, SIGUSR2) == -1)
			ft_error(RED "ERROR: " RST_CLR "Connection not established.");
	g_nb_signals++;
}

static void	cut_bits(pid_t pid, char to_send)
{
	char	c;
	int		nb;

	c = 0;
	while (c < 8)
	{
		nb = (to_send >> c++) & 1;
		usleep(800);
		send_sign(pid, nb);
	}
}

static void	cut_str(pid_t pid, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		cut_bits(pid, str[i++]);
	cut_bits(pid, 0);
}

static void	signal_handler(int signo)
{
	(void)signo;
	ft_putnbr_fd(g_nb_signals, STDOUT_FILENO);
	ft_putstr_fd(" bits received.\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char const *argv[])
{
	struct sigaction	action;

	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error(RED "ERROR: " RST_CLR "Unable to create handler for SIGUSR2.");
	if (argc == 3)
		cut_str(ft_atoi(argv[1]), argv[2]);
	else if (argc < 3)
	{
		ft_putstr_fd(RED"ERROR: "RST_CLR"Too few arguments.\n", STDOUT_FILENO);
		ft_error(YEL "\nUsage:\n$ ./client [Servers's PID] [Message]" RST_CLR);
	}
	else
	{
		ft_putstr_fd(RED"ERROR: "RST_CLR"Too many arguments.\n", STDOUT_FILENO);
		ft_error(YEL "\nUsage:\n$ ./client [Servers's PID] [Message]" RST_CLR);
	}
	while (true)
		pause();
	return (0);
}
