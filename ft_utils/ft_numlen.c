/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:19:19 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/07 14:19:25 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int ft_numlen(long n)
{
    int i;
    
    i = 0;
    if(n == 0)
        return (1);
    if(n < 0)
        n *= (-1);
    while(n)
    {
        i++;
        n = n / 10;
    }
    return (i);
}