/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:10:05 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 17:56:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	get_fct(int c, va_list ap)
{
	int	tot;

	tot = 0;
	if (c == 'c')
		tot += single_char(va_arg(ap, unsigned int));
	else if (c == 's')
		tot += putstr(va_arg(ap, char *));
	else if (c == 'p')
		tot += ft_itoa_adr(va_arg(ap, unsigned long));
	else if (c == 'd')
		tot += ft_itoa(va_arg(ap, int), "0123456789", 10);
	else if (c == 'i')
		tot += ft_itoa(va_arg(ap, int), "0123456789", 10);
	else if (c == 'u')
		tot += ft_itoa(va_arg(ap, unsigned int), "0123456789", 10);
	else if (c == 'x')
		tot += ft_itoa(va_arg(ap, unsigned int), "0123456789abcdef", 16);
	else if (c == 'X')
		tot += ft_itoa(va_arg(ap, unsigned int), "0123456789ABCDEF", 16);
	else
		tot += print_percent();
	return (tot);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			tot;

	if (!str)
		return (-1);
	va_start(ap, str);
	i = 0;
	tot = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			tot += get_fct(str[i + 1], ap);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			tot++;
			i++;
		}
	}
	va_end(ap);
	return (tot);
}
