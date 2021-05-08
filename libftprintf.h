/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:41:40 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:41:47 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_format
{
	char		flag;
	int			width;
	char		precision;
	int			number;
}				t_format;

void			zeros(int n);
void			spaces(int n);
int				istype(char ch);
int				max(int a, int b);
void			strprint(char *str, int i);
char			*utoi(unsigned int n);
int				isprepros(char ch);
int				str_null(t_format block);
void			start_point(t_format *block);
char			*ft_strdup(const char *str);
char			*ft_lutoa(unsigned long n);
char			*to_string(char ch, va_list ap);
int				final01(t_format block, char *str);
int				final02(t_format block, char *str);
int				final03(t_format block, char *str);
int				final04(t_format block, char *str);
int				last_check(char ch, t_format block, va_list ap);
t_format		root_check(const char *p, int *i, va_list ap);
void			prepros(const char *p, int *i, t_format *block, va_list ap);
char			*ft_itoa(int n);
char			*ft_hex(unsigned int n, char ch);
char			*from_int(char ch, va_list ap);
int				ft_atoi(const char *p);
char			*ft_ctoa(int ch);
int				ft_printf(const char *apformat, ...);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
size_t			ft_strlen(char *str);

#endif
