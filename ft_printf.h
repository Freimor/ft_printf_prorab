/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:09:47 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/17 11:58:39 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

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

#endif // !FT_PRINTF_H