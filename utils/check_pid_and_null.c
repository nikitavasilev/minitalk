/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pid_and_null.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:20:24 by nvasilev          #+#    #+#             */
/*   Updated: 2021/11/07 22:20:52 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	check_pid_and_null(const char *argv[])
{
	size_t	i;

	i = 0;
	if (!argv[1][0])
		ft_error(RED "ERROR: " RST_CLR "Wrong PID.");
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
			ft_error(RED "ERROR: " RST_CLR "Wrong PID.");
	}
	if (!argv[2][0])
		ft_error(RED "ERROR: " RST_CLR "Empty string.");
}
