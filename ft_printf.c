/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:04:36 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/02 16:04:40 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void flags_checker(char c, t_args *args)
{
    if (c == '-')
        args->flags.minus = 1;
    else if (c == '+')
        args->flags.plus = 1;
    else if (c == '#')
        args->flags.hash = 1;
    else if (c == '0')
        args->flags.ziro = 1;
    else if (c == ' ')
        args->flags.space = 1;
}

static void formater(const char *frmt, va_list ap)
{
    printf("\ndebuger\n");
    t_args args;
    int i;
    
    i = 0;
    while(frmt[i] && frmt[i++] != '%')
        ;
    while(ft_strchr("-+ 0#", frmt[i]))
        flags_checker(frmt[i++], &args);
    if (ft_isdigit(frmt[i]))
        args.width = ft_atoi(&frmt[i]);
    while(ft_isdigit(frmt[i]))
        i++;
    if (frmt[i++] == '.')
        args.precision = ft_atoi(&frmt[i]);
    

    printf("hash %d\n", args.flags.hash);
    printf("minus %d\n", args.flags.minus);
    printf("plus %d\n", args.flags.plus);
    printf("space %d\n", args.flags.space);
    printf("ziro %d\n", args.flags.ziro);

    printf("width %d\n", args.width);
    printf("prec %d\n", args.precision);


    printf("%s", va_arg(ap, char *));
    
}

int ft_printf(const char *frmt, ...)
{
    // int i;
    va_list ap;

    // i = 0;
    printf("\ndebuger\n");
    va_start(ap, frmt);
    formater(frmt, ap);
    va_end(ap);
    return(0);
}