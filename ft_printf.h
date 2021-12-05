/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:04:50 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/02 16:04:57 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
#define FT_LIBFT_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
// Libft functions
int	    ft_isdigit(int c);
char	*ft_itoa(int n);
int     ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
// Libft functions
/********Flags******/
typedef struct t_flags
{
    int minus;
    int plus;
    int hash;
    int ziro;
    int space;
} t_flags;

typedef struct t_args
{
    int     width;
    int     precision;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    int     length;
    char    type;
    t_flags flags;
}   t_args;
/********Flags******/
void ft_putchar(char c);
void    ft_putstr(char *s);
void    ft_putnbr(int n);
void    ft_itohup(int n);
void    ft_itohlow(int n);
int     ft_printf(const char *frmt, ...);

#endif
