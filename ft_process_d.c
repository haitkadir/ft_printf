/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:00:51 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/07 23:01:00 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int print_sign(t_args args, int argument)
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

static int print_precicion(int i)
{
    int len;

    len = 0;
    while(i--)
        len += ft_putchar('0');
    return (len);
}

static int print_width(int i, char c)
{
    int len;

    len = 0;
    while(i--)
        len += ft_putchar(c);
    return (len);
}

int process_d(int argument, t_args args)
{
    int len;
    char rest;

    len = 0;
    rest = ' ';
    if(!(args.precision) && !(args.flags.minus) && (args.flags.ziro))
        rest = '0';
    if(args.precision >= ft_numlen(argument))
        args.precision -= ft_numlen(argument);
    else
        args.precision = 0;
    if(args.width >= args.precision + ft_numlen(argument))
        args.width -= (args.precision + ft_numlen(argument));
    else
        args.width = 0;
    if(args.width && (argument < 0 || args.flags.plus || args.flags.space))
        args.width -= 1;
    
    if (args.flags.minus)
    {
        len += print_sign(args, argument);
        len += print_precicion(args.precision);
        len += ft_putnbr(argument);
        len += print_width(args.width, rest);
    }
    else
    {
        len += print_sign(args, argument);
        len += print_width(args.width, rest);
        len += print_precicion(args.precision);
        len += ft_putnbr(argument);
    }

    return (len);
}
















































// int process_d(int argument, t_args args)
// {

//     int len;
//     char c;
//     int pre;
//     int i;

//     len = 0;
//     pre = 0;

//     // printf("width:%d\n", args.width);
//     // printf("pre:%d\n", args.precision);

//     if (args.flags.ziro && args.flags.minus)
//         args.flags.ziro = 0;
//     if (args.flags.plus && args.flags.space)
//         args.flags.space = 0;
//     if (args.precision && args.flags.ziro)
//         args.flags.ziro = 0;

//     // pre = ft_numlen(argument);
//     // if (args.precision > pre)
//     //     pre = args.precision;

//     // if (args.width > pre)
//     //     pre = args.width - pre;

//     c = ' ';
//     if (args.flags.ziro)
//         c = '0';
//     if (args.precision > ft_numlen(argument))
//     {
//         if (args.flags.minus)
//         {
//             if (args.flags.plus && argument >= 0)
//                 len += ft_putchar('+');
//             ft_putnbr(argument);
//             i = args.precision - ft_numlen(argument);
//             while (i--)
//                 len += ft_putchar('0');
//             while (pre--)
//                 len += ft_putchar(c);
//         }
//         else
//         {
//             // while (pre--)
//             //     len += ft_putchar(c);
//             i = args.precision - ft_numlen(argument);
//             while (i--)
//                 len += ft_putchar('0');
//             if (args.flags.plus && argument >= 0)
//                 len += ft_putchar('+');
//             ft_putnbr(argument);
//         }
//     }
//     else
//     {
//         if (args.flags.plus && argument >= 0)
//             len += ft_putchar('+');
//         ft_putnbr(argument);
//         len += ft_numlen(argument);
//     }

//     return (len);
// }