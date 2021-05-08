/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:37:25 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:37:28 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_lutoa(unsigned long n)
{
	char				*hex;
	unsigned long		temp;
	int					len;

	if (!n)
		return (ft_strdup("0"));
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
			hex[len] = temp + 87;
		n = n / 16;
	}
	return (hex);
}
