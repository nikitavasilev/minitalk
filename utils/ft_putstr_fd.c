/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:15 by nvasilev          #+#    #+#             */
/*   Updated: 2021/10/14 15:54:45 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putstr_fd(const char *str, int fd)
{
	while (*str)
		ft_putchar_fd(*(str++), fd);
}
