/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:05:07 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/02 16:05:10 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, &*s++, 1);
}

void    ft_putnbr(int n)
{
    ft_putstr(ft_itoa(n));
}

void    ft_itohup(int n)
{
    long ln;
    char *base;

    ln = (long)n;
    base= "0123456789ABCDEF";
    if(ln < 0)
    {
        ft_putchar('-');
        ln = ln * -1;
    }
    if (ln >=0 && ln < 16)
        ft_putchar(base[ln]);
    else if (ln > 15 && ln <= 2147483648)
    {
        ft_itohup(ln / 16);
        ft_itohup(ln % 16);
    }
}

void    ft_itohlow(int n)
{
    long ln;
    char *base;

    ln = (long)n;
    base= "0123456789abcdef";
    if(ln < 0)
    {
        ft_putchar('-');
        ln = ln * -1;
    }
    if (ln >=0 && ln < 16)
        ft_putchar(base[ln]);
    else if (ln > 15 && ln <= 2147483648)
    {
        ft_itohlow(ln / 16);
        ft_itohlow(ln % 16);
    }
}