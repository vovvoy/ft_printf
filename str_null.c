/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 05:52:37 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/25 05:52:52 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		str_null(t_format block)
{
	char	*str;
	int		len;

	str = "(null)";
	len = ft_strlen(str);
	if (block.precision == '.' && block.number < len)
		len = block.number;
	if (block.precision == '.' && block.number > len)
		block.number = len;
	if (block.flag != '-')
		spaces(block.width - len);
	write(1, str, len);
	if (block.flag == '-')
		spaces(block.width - len);
	return (max(max(block.width, block.number), len));
}
