/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:34:27 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:35:21 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *p)
{
	int					isneg;
	unsigned long long	value;

	isneg = 1;
	value = 0;
	while (*p == '\t' || *p == '\n' || *p == '\v' ||
			*p == '\f' || *p == '\r' || *p == ' ')
		p++;
	if (*p == '-')
		isneg = -1;
	if (*p == '+' || *p == '-')
		p++;
	while (*p >= '0' && *p <= '9')
	{
		value *= 10;
		if (value > LLONG_MAX || (long long)value <= LLONG_MIN)
		{
			if (isneg == -1)
				return (0);
			return (-1);
		}
		value += *p - '0';
		p++;
	}
	return (value * isneg);
}
