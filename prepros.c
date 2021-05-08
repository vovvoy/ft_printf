/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepros.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:42:07 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:42:12 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	to_int(const char *p, int *i)
{
	int		num;

	num = 0;
	while (p[*i] >= '0' && p[*i] <= '9')
	{
		num = num * 10 + (p[*i] - 48);
		*i = *i + 1;
	}
	*i = *i - 1;
	return (num);
}

static int	asterisk(va_list ap, t_format *block, char ch)
{
	int		num;

	num = va_arg(ap, int);
	if (num < 0 && (ch == '%' || ch == '0' || ch == '-'))
	{
		num *= -1;
		block->flag = '-';
	}
	if (num < 0 && ch == '.')
		block->precision = 'n';
	return (num);
}

void		prepros(const char *p, int *i, t_format *block, va_list ap)
{
	while (isprepros(p[*i]))
	{
		if (p[*i] == '-')
			block->flag = '-';
		else if (p[*i] >= '0' && p[*i] <= '9' && (p[*i - 1] == '.'))
			block->number = to_int(p, i);
		else if (p[*i] == '0' && block->flag != '-')
			block->flag = '0';
		else if (p[*i] >= '0' && p[*i] <= '9' &&
				(p[*i - 1] == '%' || p[*i - 1] == '-' || p[*i - 1] == '0'))
			block->width = to_int(p, i);
		else if (p[*i] == '.')
		{
			block->precision = '.';
			block->number = 0;
		}
		else if (p[*i] == '*' && (p[*i - 1] == '%' ||
					p[*i - 1] == '-' || p[*i - 1] == '0'))
			block->width = asterisk(ap, block, p[*i - 1]);
		else if (p[*i] == '*' && p[*i - 1] == '.')
			block->number = asterisk(ap, block, p[*i - 1]);
		*i = *i + 1;
	}
}
