/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:27:54 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/17 22:10:45 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char a)
{
	write(1, &a, 1);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	while (str[i] != '\0')
		i++;
	return(i);
}

void	str_copy(char *source, char *dest)
{
	while (*source != '\0')
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}

char	*makestr(char *restr, char add)
{
	char	*newstr;
	char	temp[ft_strlen(restr) + 1];
	int		i;

	while (restr[i] != '\0')
	{
		temp[i] = restr[i];
		i++;
	}
	temp[i] = '\0';
	free(restr);
	newstr = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (temp[i] != '\0')
	{
		newstr[i] = temp[i];
		i++;
	}
	newstr[i] = add;
	newstr[++i] = '\0';
	return(newstr);
}

void	print_bits(size_t size, void *ptr, char space)
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

void	bits_to_str(size_t size, void *ptr, char *str)
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
			makestr(str, byte + '0');
			j--;
		}
	j = 7;
	i--;
	}
}

void	main(void)
{
	char *str;
	long double fl;

	fl = 3.5;
	str = (char *)malloc(sizeof(char) * 1);
	bits_to_str(8, &fl, str);
	print_bits(8, &fl, 0);
	printf("\n");
	printf("%s\n", str);
}