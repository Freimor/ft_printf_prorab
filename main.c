/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:09:44 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/17 14:29:22 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char a)
{
	write(1, &a, 1);
}

void print_bits(size_t size, void *ptr, char space)
{
	unsigned char *b;
	unsigned char byte;
	int i;
	int j;

	b = (unsigned char*)ptr;
	i = size - 1;
	j = 7;
	while (i >= 0)
	{
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putchar(byte + '0');
			j--;
		}
	if (space == 1)
		ft_putchar(' ');
	j = 7;
	i--;
	}
	ft_putchar('\n');
}

int		float_op(long double *raw)
{
	u_ld un_deb;
	uint64_t mantissa, sign;
	long double i = 3.5;
	
	un_deb.d = i;
	mantissa = un_deb.bits.mantissa;
	
	printf("uint = %ld\n", un_deb.bits.mantissa);
	printf("mant = %ld\n", mantissa);
	print_bits(10, &(un_deb.d), 1);
	print_bits(10, &mantissa, 1);
	write(1, " ^ mantissa", 13);
	ft_putchar('\n');
}

int	main(void)
{
	long double	raw;
	raw = 3.625;
	float_op(&raw);
	return(0);
}