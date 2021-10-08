/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:05:49 by nvasilev          #+#    #+#             */
/*   Updated: 2021/10/08 17:24:12 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_putchar_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}
