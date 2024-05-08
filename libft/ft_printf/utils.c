/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:11:23 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 17:56:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	single_char(unsigned int c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr(const char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
