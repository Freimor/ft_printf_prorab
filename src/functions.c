/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:27:54 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/21 19:16:41 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*char	*makestr(char *restr, char add)
{
	char	*newstr;
	char	temp[ft_strlen(restr) + 1];
	int		i;

	i = 0;
	while (restr[i] != '\0')
	{
		temp[i] = restr[i];
		i++;
	}
	temp[i] = '\0';
	free(restr);
	newstr = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (temp[i] != '\0')
	{
		newstr[i] = temp[i];
		i++;
	}
	newstr[i] = add;
	newstr[++i] = '\0';
	return(newstr);
}*/

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

/*void	bits_to_str(size_t size, void *ptr, char *str)
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
			str = makestr(str, byte + '0');
			j--;
		}
	j = 7;
	i--;
	}
}*/

char	*bits_to_str(size_t size, void *ptr)
{
	unsigned char	*b;
	unsigned char	byte;
	char			*str;
	int				l;
	int				i;
	int				j;

	b = (unsigned char*)ptr;
	i = size - 1;
	j = 7;
	l = 0;
	str = (char *)malloc(sizeof(char) * (size * 8 + 1));
	while (i >= 0)
	{
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			str[l] = byte + '0';
			l++;
			j--;
		}
	j = 7;
	i--;
	}
	str[l] = '\0';
	return (str);
}

int		ft_pow(int a, int b)
{
	int	num;

	num = 1;
	while ((b) > 0)
	{
		num *= a;
		b--;
	}
	return(num);
}

int		strbinary_to_decimal(char *str)
{
	int	i;
	int num;
	int decimal;

	if (str == NULL)
		return (-1);
	i = 0;
	num = ft_strlen(str);
	decimal = 0;
	while (i < num)
	{
		if (str[i] == '1')
			decimal += ft_pow(2, num - i - 1);
		i++;
	}
	return(decimal);
}

char	*ft_strcopy_2point(char *str, int a, int b)
{
	int		i;
	char	*dest;

	i = 0;
	if (a < 0 || b < 0 || b < a || str == NULL)
		return (NULL);
	while (i < b - a)
	{
		str[a + i] = dest[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

s_doub	drop_to_struct_double(char *str)
{
	s_doub	struc;
	int		i;
	int		j;
	char	exponen[15 + 1];

	struc.sign = str[0] - '0';
	i = 1;
	while (i < 16)
	{
		exponen[i - 1] = str[i];
		i++;
	}
	exponen[i - 1] = '\0';
	struc.exponent = strbinary_to_decimal(exponen) - 16383 + 1;
	i = 16;
	while (i < 16 + struc.exponent)
	{
		struc.up_mantis[i - 16] = str[i];
		i++;
	}
	struc.up_mantis[i - 16] = '\0';
	j = i;
	while (i < 80)
	{
		struc.down_mantis[i - j] = str[i];
		i++;
	}
	struc.down_mantis[i - j] = '\0';
	printf("sign -> %d\n", struc.sign);
	printf("up_mantiss -> %s\n", struc.up_mantis);
	printf("down_mantiss -> %s\n", struc.down_mantis);	
	printf("exponen -> %d\n", struc.exponent);
	//struc.exponent = rework_expo(exponen);
	//printf("%d\n", struc.sign);
	//printf("%s\n", exponen);
	return(struc);
}

int	main(void)
{
	char *str;
	long double fl;
	u_ld rest;

	fl = -42.21;
	rest.d = fl;
	//bits_to_str(10, &fl, str);
	str = bits_to_str(10, &fl);
	printf("%s\n", str);
	print_bits(10, &fl, 0);
	drop_to_struct_double(bits_to_str(10, &fl));
	//print_bits(10, &fl, 1);
	//printf("\n");
	//printf("\n");
	//printf("%s\n", str);
}