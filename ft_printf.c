/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:42 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:37:45 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		start_point(t_format *block)
{
	block->flag = 'n';
	block->width = 0;
	block->precision = 'n';
	block->number = -1;
}

t_format	root_check(const char *p, int *i, va_list ap)
{
	t_format	block;

	*i = *i + 1;
	start_point(&block);
	if (isprepros(p[*i]))
		prepros(p, i, &block, ap);
	return (block);
}

int			ft_printf(const char *apformat, ...)
{
	va_list		ap;
	int			count;
	int			i;
	t_format	block;

	i = 0;
	count = 0;
	va_start(ap, apformat);
	while (apformat[i] != '\0' && count > -1)
	{
		if (apformat[i] != '%')
		{
			ft_putchar_fd(apformat[i++], 1);
			count++;
		}
		else
		{
			block = root_check(apformat, &i, ap);
			count += last_check(apformat[i++], block, ap);
		}
	}
	va_end(ap);
	return (count);
}
