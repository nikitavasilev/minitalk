/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:27:43 by nvasilev          #+#    #+#             */
/*   Updated: 2021/10/08 19:05:07 by nvasilev         ###   ########.fr       */
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
	return (0);
}
