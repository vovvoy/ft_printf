/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprepros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:40:17 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:40:20 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	isprepros(char ch)
{
	char *prepros;

	prepros = "0123456789*.-";
	while (*prepros)
		if (*prepros++ == ch)
			return (1);
	return (0);
}
