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

static int process_data(t_args args, va_list **ap)
{
    int len;

    len = 0;
    if (ft_tolower(args.type) == 'd' || ft_tolower(args.type) == 'i')
    {
        len = process_d(va_arg(*(*ap), int), args);
    }
    return (len);
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

static int manage_flags(const char *frmt, int i, t_args *args)
{
    while (ft_strchr("-+ 0#", frmt[i]))
        flags_checker(frmt[i++], &args);
    if (ft_isdigit(frmt[i]))
        args->width = ft_atoi(&frmt[i]);
    while (ft_isdigit(frmt[i]))
        i++;
    if (frmt[i] == '.')
    {
        i++;
        args->precision = ft_atoi(&frmt[i]);
    }
    while (ft_isdigit(frmt[i]))
        i++;
    if (ft_strchr("cspdiuxX", frmt[i]))
        args->type = frmt[i];
    else
        return(-1);
    return (i);
}

static int formater(va_list *ap, const char *frmt)
{
    int i;
    int len;
    t_args args;

    len = i = 0;
    while (frmt[i])
    {
        ft_bzero(&args.flags, sizeof(args.flags));
        ft_bzero(&args, sizeof(args));
        if (frmt[i] == '%' && frmt[i + 1] == '%')
            len += ft_putchar(frmt[++i]);
        else if (frmt[i] == '%' &&  frmt[i + 1] != '%')
        {
            i = manage_flags(frmt, i + 1, &args);
            if (i == -1)
                return (i);
            len += process_data(args, &ap);
        }
        else
            len += ft_putchar(frmt[i]);
        i++;
    }
    return (len);
}

int ft_printf(const char *frmt, ...)
{
    int len;
    va_list ap;

    len = 0;
    va_start(ap, frmt);
    len += formater(&ap, frmt);
    va_end(ap);
    return (len);
}
