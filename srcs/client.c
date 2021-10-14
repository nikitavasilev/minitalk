/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:27:43 by nvasilev          #+#    #+#             */
/*   Updated: 2021/10/14 18:00:58 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	decimal_conversion(char ascii, int power, int pid)
{
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error("\033[0;31mERROR:\033[0m Connection not established.");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error("\033[0;31mERROR:\033[0m Connection not established.");
	}
	usleep(100);
}

static void	signal_handler(int signo)
{
	(void)signo;
	ft_putstr_fd("Signal received.\n", STDOUT_FILENO);
}

static int	send_message(int server_pid, const char *msg)
{
	size_t	i;

	i = 0;
	while (msg[i])
		decimal_conversion(msg[i++], 7, server_pid);
	return (0);
}

int	main(int argc, char const *argv[])
{
	struct sigaction	action;

	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error("ERROR: Unable to create handler for SIGUSR2.");
	if (argc == 3)
		send_message(ft_atoi(argv[1]), argv[2]);
	else if (argc < 3)
	{
		ft_putstr_fd("ERROR: Too few arguments.\n", STDOUT_FILENO);
		ft_error("\nUsage:\n$ ./client [Servers's PID] [Message]");
	}
	else
	{
		ft_putstr_fd("ERROR: Too many arguments.\n", STDOUT_FILENO);
		ft_error("\nUsage:\n$ ./client [Servers's PID] [Message]");
	}
	while (true)
		pause();
	return (0);
}
