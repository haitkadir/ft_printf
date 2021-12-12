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
    if (args.type == 'd' || args.type == 'i')
        len = process_d(va_arg(*(*ap), int), args);
    else if (args.type == 'u')
        len = process_u(va_arg(*(*ap), unsigned int), args);
    else if (ft_tolower(args.type) == 'x')
        len = process_x(va_arg(*(*ap), unsigned int), args);
    else if (args.type == 'p')
        len = process_p(va_arg(*(*ap), unsigned long), args);
    else if (args.type == 's')
        len = process_s(va_arg(*(*ap), char *), args);
    else if (args.type == 'c')
        len = process_c(va_arg(*(*ap), int), args);
    return (len);
}

static int formater(va_list *ap, const char *frmt)
{
    int i;
    int len;
    t_args args;

    i = 0;
    len = 0;
    while (frmt[i])
    {
        ft_bzero(&args.flags, sizeof(args.flags));
        ft_bzero(&args, sizeof(args));
        if (frmt[i] == '%' && frmt[i + 1] == '%')
            len += ft_putchar(frmt[++i]);
        else if (frmt[i] == '%' &&  frmt[i + 1] != '%')
        {
            i = manage_flags(frmt, i + 1, &args);
            len += process_data(args, &ap);
        }
        else
            len += ft_putchar(frmt[i]);
        i++;
    }
    return (len);
}
static int check_minus(t_args args)
{
    if(args.flags.ziro && ft_strchr("csp", args.type))
        return (1);
    if(args.is_precision && ft_strchr("sdiuxX", args.type))
        return (1);
    if(args.flags.hash && !ft_strchr("xX", args.type))
        return (1);
    if(args.flags.space && !ft_strchr("sdi", args.type))
        return (1);
    if(args.flags.space && !ft_strchr("sdi", args.type))
        return (1);
    return (0);
}
static int check_incomptable_flags(const char *frmt)
{
    t_args args;
    int i;

    ft_bzero(&args.flags, sizeof(args.flags));
    ft_bzero(&args, sizeof(args));
    i = 0;
    manage_flags(frmt, 0, &args);
    if(args.type == 'd')
        if(args.flags.hash)
            return (1);
    // else if(args.type == 's')
}

static int check_error(const char *frmt)
{
    int i;
    int j;
    int check_doubel_pre;
    const char    *copy;

    i = 0;
    j = 0;
    check_doubel_pre = 0;
    copy = NULL;
    while(frmt[i])
    {
        if(frmt[i] == '%')
        {
            copy = &frmt[i + 1];

            while(ft_strchr(" -+#.0123456789", copy[j]))
            {
                if(copy[j] == '.')
                    check_doubel_pre++;
                j++;
            }
            if(!ft_strchr("cspdiuxX", copy[j]) || check_doubel_pre > 1)
                return (1);
        }
        i++;
    }
    return (0);
}
int ft_printf(const char *frmt, ...)
{
    int len;
    va_list ap;

    len = 0;
    if(check_error(frmt))
        return (-1);
    va_start(ap, frmt);
    len += formater(&ap, frmt);
    va_end(ap);
    return (len);
}
