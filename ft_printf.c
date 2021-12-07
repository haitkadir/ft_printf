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

static void process_data(t_args args, va_list **ap)
{
    // int len;
    
    if (ft_tolower(args.type) == 'd' || ft_tolower(args.type))
    {
        process_d(va_arg(*ap, int), args);
    }
}

static void flags_checker(char c, t_args **args)
{
    if (c == '-')
        (*args)->flags.minus = 1;
    else if (c == '+')
        (*args)->flags.plus = 1;
    else if (c == '#')
        (*args)->flags.hash = 1;
    else if (c == '0')
        (*args)->flags.ziro = 1;
    else if (c == ' ')
        (*args)->flags.space = 1;
}

static void manage_flags(const char *frmt, int *index, t_args *args)
{
    int i;
    
    i = 0;
    while(ft_strchr("-+ 0#", frmt[i]))
        flags_checker(frmt[i++], &args);
    if (ft_isdigit(frmt[i]))
        args -> width = ft_atoi(&frmt[i]);
    while(ft_isdigit(frmt[i]))
        i++;
    if (frmt[i++] == '.')
        args -> precision = ft_atoi(&frmt[i]);
    while(ft_isdigit(frmt[i]))
        i++;
    if(ft_isalpha(frmt[i]))
        args -> type = frmt[i];
     index += i;
}

static void formater(va_list *ap, const char *frmt)
{
    int i;
    t_args args;
    
    i = 0;
     while(frmt[i])
     {
       if (frmt[i] == '%' && frmt[i + 1] == '%')
         ft_putchar(frmt[++i]);
       else if (frmt[i] == '%' && frmt[i + 1] != '%')
       {
         manage_flags(&frmt[i], &i, &args);
         process_data(args, &ap);
       }
       else
         ft_putchar(frmt[i]);
       i++; 
     }
}

int ft_printf(const char *frmt, ...)
{
    va_list ap;

    va_start(ap, frmt);
    formater(frmt, &ap);
    va_end(ap);
    return(0);
}