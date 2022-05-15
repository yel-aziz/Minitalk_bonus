/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:48:48 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/01/13 13:28:09 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_printhex( unsigned long n);
int	ft_putnbr_base(unsigned long n);
int	ft_putnbr(int n);
int	ft_puthex(unsigned long n);
int	ft_putstr(char *s);
int	ft_putnbrunsi(unsigned int n);
int	ft_printf(const char *fmt, ...);
int	ft_puthexup(unsigned long n);
int	ft_atoi(const char *str);

#endif
