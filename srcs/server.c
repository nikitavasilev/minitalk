/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:04:16 by nvasilev          #+#    #+#             */
/*   Updated: 2021/10/14 15:53:19 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	signal_handler(int signo, siginfo_t *siginfo, void *ucontext)
{
	static int	ascii = 0;
	static int	power = 0;

	(void)ucontext;
	if (signo == SIGUSR1)
		ascii += 1 << (7 - power);
	power += 1;
	if (power == 8)
	{
		ft_putchar_fd(ascii, STDOUT_FILENO);
		power = 0;
		ascii = 0;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			ft_error("Error signal.");
	}
}

int	main(int argc, char const *argv[])
{
	struct sigaction	action;

	(void)argv;
	if (argc != 1)
	{
		ft_error("Error: Too many arguments");
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("Server's PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_error("ERROR: Unable to create handler for SIGUSR1.");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error("ERROR: Unable to create handler for SIGUSR2.");
	while (true)
		pause();
	return (0);
}
