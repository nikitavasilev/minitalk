/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:44:56 by nvasilev          #+#    #+#             */
/*   Updated: 2021/10/14 18:00:55 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _XOPEN_SOURCE 700
# define _DEFAULT_SOURCE

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdbool.h>

// UTILS FUNCTIONS
int		ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_error(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
