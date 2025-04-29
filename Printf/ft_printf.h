/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:23:33 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/29 17:39:05 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../Libft/libft.h"
#include <stdarg.h>

int     ft_printf(const char *, ...);
void    print_char(va_list arg);
void    print_str(va_list arg);






#endif