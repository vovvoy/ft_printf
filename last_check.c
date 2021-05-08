/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_chack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:41:21 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:41:24 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*to_string(char ch, va_list ap)
{
	if (ch == 'i' || ch == 'd')
		return (ft_itoa(va_arg(ap, int)));
	if (ch == 'u')
		return (utoi(va_arg(ap, unsigned int)));
	if (ch == 'x' || ch == 'X')
		return (ft_hex(va_arg(ap, unsigned int), ch));
	if (ch == 'c')
		return (ft_ctoa(va_arg(ap, int)));
	if (ch == 's')
		return (va_arg(ap, char *));
	return (ft_lutoa((unsigned long)va_arg(ap, void *)));
}

int			last_check(char ch, t_format block, va_list ap)
{
	char		*str;

	if (ch == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	str = to_string(ch, ap);
	if (ch == 'i' || ch == 'd' || ch == 'u' || ch == 'x' || ch == 'X')
		return (final01(block, str));
	if (ch == 's')
		return (final02(block, str));
	if (ch == 'c')
		return (final03(block, str));
	return (final04(block, str));
}
