/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:43:47 by ljerrica          #+#    #+#             */
/*   Updated: 2020/06/22 14:43:49 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			final01(t_format block, char *str)
{
	int		len;

	if (str == NULL)
		return (str_null(block));
	len = ft_strlen(str);
	if (str[0] == '0' && block.number == 0)
		len = 0;
	if (block.flag == '0' && block.precision == '.')
		block.flag = 'n';
	if (str[0] == '-')
		block.number = block.number + 1;
	if (block.flag == 'n')
		spaces(block.width - max(len, block.number));
	if (str[0] == '-')
		write(1, "-", 1);
	if (block.flag == '0')
		zeros(block.width - max(len, block.number));
	zeros(block.number - len);
	str[0] == '-' ? strprint(str, 1) : write(1, str, len);
	if (block.flag == '-')
		spaces(block.width - max(len, block.number));
	free(str);
	return (max(max(block.width, block.number), len));
}

int			final02(t_format block, char *str)
{
	int			len;

	if (str == NULL)
		return (str_null(block));
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

int			final03(t_format block, char *str)
{
	if (str == NULL)
		return (-10000000);
	if (block.flag != '-')
		spaces(block.width - 1);
	write(1, str, 1);
	if (block.flag == '-')
		spaces(block.width - 1);
	free(str);
	return (max(block.width, 1));
}

int			final04(t_format block, char *str)
{
	int		len;

	if (str == NULL)
		return (-10000000);
	len = ft_strlen(str) + 2;
	if (block.number)
		block.number = block.number + 2;
	if (block.flag == 'n')
		spaces(block.width - max(block.number, len));
	write(1, "0x", 2);
	if (block.flag == '0')
		zeros(block.width - max(block.number, len));
	zeros(block.number - len);
	if (!(block.number == 0 && str[0] == '0'))
		write(1, str, ft_strlen(str));
	else
		len -= 1;
	if (block.flag == '-')
		spaces(block.width - max(block.number, len));
	free(str);
	return (max(max(block.width, block.number), len));
}
