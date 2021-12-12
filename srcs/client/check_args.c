/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:20:24 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/12 17:19:12 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	check_pid_and_null(const char *argv[])
{
	size_t	i;

	i = 0;
	if (ft_atoi(argv[1]) <= 0)
		ft_error(RED "ERROR: " RST_CLR "Invalid server PID.");
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
			ft_error(RED "ERROR: " RST_CLR "Invalid server PID.");
	}
	if (!argv[2][0])
		ft_error(RED "ERROR: " RST_CLR "Empty string.");
}

void	check_args(int argc, char const *argv[])
{
	if (argc == 3)
	{
		check_pid_and_null(argv);
		cut_str(ft_atoi(argv[1]), argv[2]);
	}
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
}
