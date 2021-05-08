/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:36:40 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:36:44 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_hex(unsigned int n, char ch)
{
	char			*hex;
	unsigned int	temp;
	unsigned int	len;

	len = 2;
	temp = n;
	while (temp /= 16)
		len++;
	if ((hex = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	hex[--len] = '\0';
	while (len--)
	{
		temp = n % 16;
		if (temp < 10)
			hex[len] = temp + 48;
		else
			hex[len] = (ch == 'X') ? temp + 55 : temp + 87;
		n = n / 16;
	}
	return (hex);
}
