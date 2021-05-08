/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:43:34 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:43:37 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	spaces(int n)
{
	if (n < 0)
		return ;
	n++;
	while (--n)
		write(1, " ", 1);
}

void	zeros(int n)
{
	if (n < 0)
		return ;
	n++;
	while (--n)
		write(1, "0", 1);
}

void	strprint(char *str, int i)
{
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
