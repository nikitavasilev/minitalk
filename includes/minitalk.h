/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:44:56 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/12 18:46:53 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _XOPEN_SOURCE 700
# define _DEFAULT_SOURCE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdbool.h>
# include "ansi_colors.h"

// CLIENT
void	check_args(int argc, char const *argv[]);
void	cut_str(pid_t pid, const char *str);

// UTILS FUNCTIONS
int		ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_error(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr_color_fd(const char *color, const char *str, int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);

#endif
