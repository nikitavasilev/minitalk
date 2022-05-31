/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:44:56 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/31 12:59:43 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 199309L
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <sys/types.h>

typedef struct s_fill
{
	char			buffer[BUFFER_SIZE];
	size_t			size;
	unsigned char	byte;
}	t_fill;

// CLIENT
void	check_args(int argc, char const *argv[]);
void	cut_str(pid_t pid, const char *str);

// UTILS FUNCTIONS
int		ft_putchar_fd(int c, int fd);
int		ft_putstr_fd(const char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_error(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr_color_fd(const char *color, const char *str, int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);

#endif
