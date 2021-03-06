/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:15 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/30 04:15:45 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk.h"

int	ft_putstr_fd(const char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}
