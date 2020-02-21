/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:09:47 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/21 17:23:25 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "../libft/includes/libft.h"

typedef union	UN_floats
{
	long double	d;
	struct
	{
		uint64_t sign		: 1;
		uint64_t exponent	: 15;   //kol vo chisel do ,
		uint64_t mantissa	: 64;
	}	bits;
} u_ld;

typedef struct double_segment
{
	int		sign;
	int		exponent;
	char	up_mantis[64];
	char	down_mantis[64];
} s_doub;

void print_bits(size_t size, void *ptr, char space);

#endif // !FT_PRINTF_H