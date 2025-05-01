/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:23:33 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/01 20:46:21 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../Libft/libft.h" //VERIFICAR ISTO
#include <stdarg.h>

int		ft_printf(const char *, ...);
int    	print_char(int c);
int    	print_str(const char *str);
int     print_pointer(void * ptr);
int     print_numbers(int nb);
int     print_unsigned(unsigned int nb);
int		print_hex(unsigned long nb, const char *hex);

#endif