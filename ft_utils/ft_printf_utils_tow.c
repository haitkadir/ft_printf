/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_tow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:05:07 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/03 16:05:10 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
int print_sign(t_args args, int argument)
{
    int len;

    len = 0;
    if(argument < 0)
        len += ft_putchar('-');
    else if (args.flags.plus)
        len += ft_putchar('+');
    else if (args.flags.space)
        len += ft_putchar(' ');
    return (len);
}

int print_precicion(int i)
{
    int len;

    len = 0;
    while(i--)
        len += ft_putchar('0');
    return (len);
}

int print_width(int i, char c)
{
    int len;

    len = 0;
    while(i--)
        len += ft_putchar(c);
    return (len);
}
int	ft_put_unsigned_nbr(unsigned int nb)
{
    int len;

    len = 0;
	if (nb <= 9)
		len += ft_putchar(nb + '0');
	else if (nb > 9)
	{
		len += ft_put_unsigned_nbr(nb / 10);
		len += ft_put_unsigned_nbr(nb % 10);
	}
    return (len);
}