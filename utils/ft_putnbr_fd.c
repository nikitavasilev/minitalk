/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:24:19 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/30 04:22:20 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if ((unsigned int)n >= 10)
		ft_putnbr_fd((unsigned int)n / 10, fd);
	ft_putchar_fd((unsigned int)n % 10 + '0', fd);
}
