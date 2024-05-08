/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:11:00 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 17:56:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	len_itoa(long n, int base_len)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > base_len - 1)
	{
		len++;
		n /= base_len;
	}
	return (len);
}

int	ft_itoa(long n, char const *base, int base_len)
{
	int		len;
	int		tot;
	char	*nb;

	len = len_itoa(n, base_len);
	tot = len;
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (0);
	if (n < 0)
	{
		nb[0] = '-';
		n *= -1;
	}
	nb[len] = '\0';
	while (n > base_len - 1)
	{
		nb[--len] = base[n % base_len];
		n /= base_len;
	}
	nb[--len] = base[n % base_len];
	putstr(nb);
	free(nb);
	return (tot);
}

static int	len_itoa_adr(unsigned long n, unsigned long base_len)
{
	int	len;

	len = 1;
	while (n > base_len - 1)
	{
		len++;
		n /= base_len;
	}
	return (len);
}

int	ft_itoa_adr(unsigned long ptr)
{
	int		len;
	int		tot;
	char	*nb;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = len_itoa_adr(ptr, 16) + 2;
	tot = len;
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (0);
	nb[len] = '\0';
	nb[0] = '0';
	nb[1] = 'x';
	while (ptr > 15)
	{
		nb[--len] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	nb[--len] = "0123456789abcdef"[ptr % 16];
	putstr(nb);
	free(nb);
	return (tot);
}
