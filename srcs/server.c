/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:04:16 by nvasilev          #+#    #+#             */
/*   Updated: 2021/10/13 15:44:08 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signo, siginfo_t siginfo, void *ucontext)
{

}

int	main(int argc, char const *argv[])
{
	struct sigaction action;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error: Too many arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("Server's PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == SIG_ERR)
		ft_putstr_fd("ERROR: Unable to create handler for SIGUSR1.\n", STDERR_FILENO);
	if (sigaction(SIGUSR2, &action, NULL) == SIG_ERR)
		ft_putstr_fd("ERROR: Unable to create handler for SIGUSR2.\n", STDERR_FILENO);
	while (true)
		pause();
	return (0);
}
