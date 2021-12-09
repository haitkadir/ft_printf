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
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
// Libft functions
int     ft_numlen(long n);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int	    ft_tolower(int c);
int	    ft_isdigit(int c);
int	    ft_isalpha(int c);
char	*ft_itoa(long n);
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
    char    type;
    t_flags flags;
}   t_args;
/********Flags******/
int     ft_putchar(char c);
int     ft_putstr(char *s);
int     ft_putnbr(long n);
void    ft_itohup(int n);
void    ft_itohlow(int n);

int process_d(int argument, t_args args);
int     ft_printf(const char *frmt, ...);

#endif
