/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:04:16 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/12 19:03:46 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	clear_buffer(char *buffer, size_t *cursor)
{
	if (*cursor == BUFFER_SIZE - 2)
		buffer[BUFFER_SIZE - 1] = '\0';
	else
		buffer[*cursor] = '\0';
	ft_putstr_fd(buffer, STDOUT_FILENO);
	ft_bzero(buffer, ft_strlen(buffer));
	*cursor = 0;
}

static void	display_message(int to_put, siginfo_t *siginfo)
{
	static char				buffer[BUFFER_SIZE];
	static size_t			cursor = 0;
	static unsigned char	c = 0;
	static int				i = 0;

	if (kill(siginfo->si_pid, SIGUSR1) == -1)
		ft_error(RED "ERROR: " RST_CLR "Connection not established.");
	c |= (to_put << i++);
	if (i > 7)
	{
		if (cursor == BUFFER_SIZE - 2)
			clear_buffer(buffer, &cursor);
		if (c == '\0')
		{
			clear_buffer(buffer, &cursor);
			ft_putchar_fd('\n', STDOUT_FILENO);
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				ft_error(RED "ERROR: " RST_CLR "Connection not established.");
		}
		else
			buffer[cursor++] = c;
		i = 0;
		c = 0;
	}
}

static void	signal_handler(int signo, siginfo_t *siginfo, void *ucontext)
{
	static pid_t	tmp = 0;

	(void)ucontext;
	if (tmp != siginfo->si_pid)
	{
		ft_putstr_fd("\n\nMessage from process " YEL, STDOUT_FILENO);
		ft_putnbr_fd(siginfo->si_pid, STDOUT_FILENO);
		ft_putstr_fd(RST_CLR ":\n", STDOUT_FILENO);
	}
	tmp = siginfo->si_pid;
	if (signo == SIGUSR1)
		display_message(0, siginfo);
	else if (signo == SIGUSR2)
		display_message(1, siginfo);
}

int	main(int argc, char const *argv[])
{
	struct sigaction	action;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd(RED"ERROR: "RST_CLR"Too many arguments.\n", STDOUT_FILENO);
		ft_error(YEL "\nUsage:\n$ ./server" RST_CLR);
	}
	ft_putstr_fd("\nServer launched succesfully ✔️\n", STDOUT_FILENO);
	ft_putstr_fd("Server's PID: " YEL, STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd(RST_CLR, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_error(RED "ERROR: " RST_CLR "Unable to create handler for SIGUSR1.");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error(RED "ERROR: " RST_CLR "Unable to create handler for SIGUSR2.");
	while (true)
		pause();
	return (0);
}