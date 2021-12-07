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

int process_d(int argument, t_args args)
{

  int len;
  char c;
  int width;
  int i;
  
  width = 0;
  if(args.flags.ziro && args.flags.minus)
    args.flags.ziro = 0;
  if(args.flags.plus && args.flags.space)
    args.flags.space = 0;
  if(args.precision && args.flags.ziro)
    args.flags.ziro = 0;
  width = ft_numlen(argument);
  if(args.precision > width)
      width = args.precision;
  if(args.width > width)
      width = args.width - width;
    
  c = ' ';
  if(args.flags.ziro)
     c = '0'; 
  if(args.precision > ft_numlen(argument))
  {
    if(args.flags.minus)
    {
      if(args.flags.plus && argument >= 0)
        len += ft_putchar('+');
      ft_putnbr(argument);
      i = args.precision - ft_numlen(argument);
      while(i--)
        len += ft_putchar('0');
      while(width--)
       len += ft_putchar(c);
    }
    else
    {
      while(width--)
         len += ft_putchar(c);
      i = args.precision - ft_numlen(argument);
      while(i--)
        len += ft_putchar('0');
      if(args.flags.plus && argument >= 0)
        len += ft_putchar('+');
      ft_putnbr(argument);
    } 
  }
  else
  {
    if(args.flags.plus && argument >= 0)
      len += ft_putchar('+');
    ft_putnbr(argument);
    len += ft_numlen(argument);
  }
  
  return (len);
}
