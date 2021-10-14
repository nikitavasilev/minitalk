/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:27:43 by nvasilev          #+#    #+#             */
/*   Updated: 2021/10/13 14:30:48 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char const *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error: Too many arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	while (true)
		pause();
	return (0);
}
