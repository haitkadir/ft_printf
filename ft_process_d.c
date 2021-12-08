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


int process_d(long argument, t_args args)
{

    int len;
    char c;
    int pre;
    int width;
    int negative;

    len = 0;
    width = 0;
    pre = 0;
    negative = 0;

    if (args.flags.ziro && args.flags.minus)
        args.flags.ziro = 0;
    if (args.flags.plus && args.flags.space)
        args.flags.space = 0;
    if (args.precision && args.flags.ziro)
        args.flags.ziro = 0;

    if (args.precision > ft_numlen(argument))
    {
        if(args.width > args.precision)
            width = args.width - args.precision;
        pre = args.precision - ft_numlen(argument);
    }
    else if(args.width > ft_numlen(argument))
        width = args.width - ft_numlen(argument);
    if (width && args.flags.plus)
        width -= 1;

    if(argument < 0)
    {
        negative = 1;
        argument *= (-1);
        if(pre > ft_numlen(argument) + 1)
            width++;
    }

    c = ' ';
    if (args.flags.ziro)
        c = '0';

        if (!args.flags.minus)
        {
            if(negative && c == '0')
                len += ft_putchar('-');
            while(width--)
                len += ft_putchar(c);
            if(negative && c == ' ')
                len += ft_putchar('-');
            if (args.flags.plus && argument >= 0)
                len += ft_putchar('+');
            if (args.flags.space && argument >= 0)
                len += ft_putchar(' ');
            while (pre--)
                len += ft_putchar('0');
            len += ft_putnbr(argument);
        }
        else
        {
            if (args.flags.plus && argument >= 0)
                len += ft_putchar('+');
            if (args.flags.space && argument >= 0)
                len += ft_putchar(' ');
            while (pre--)
                len += ft_putchar('0');
            if(negative)
                len += ft_putchar('-');
            len += ft_putnbr(argument);
            while(width--)
                len += ft_putchar(c);
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