/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:04:16 by nvasilev          #+#    #+#             */
/*   Updated: 2021/10/08 18:32:33 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char const *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error: Too many arguments\n", 2);
		exit(0);
	}
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (true)
		pause();
	return (0);
}
