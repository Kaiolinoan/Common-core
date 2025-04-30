/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:23:33 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/30 13:46:57 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../Libft/libft.h"
#include <stdarg.h>

int		ft_printf(const char *, ...);
int    	print_char(va_list arg);
int    	print_str(va_list arg);

unsigned int    sla_function(unsigned int nb);
int		print_lowhex(va_list arg);
// int		print_uphex(va_list arg);







#endif