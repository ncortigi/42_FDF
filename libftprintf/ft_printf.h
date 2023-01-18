/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:11:46 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/28 15:11:54 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstr_int(char *str);
int	ft_puthex_int(unsigned int n, char *base);
int	ft_putnbrbase_int(int nbr, char *base);
int	ft_putchar_int(char c);
int	ft_printaddress(long unsigned n, char *base);
int	ft_putunsigned(unsigned int nbr, char *base);

#endif
