/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:58:37 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/30 12:43:29 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    print_char(va_list arg)
{
    int             count;
    int   uc;

    count = 0;
    uc = (unsigned char)va_arg(arg, int);
    count += write(1, &uc, 1);
    return (count);
}