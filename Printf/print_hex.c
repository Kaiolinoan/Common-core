/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:58:39 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/30 13:56:24 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_lowhex(va_list arg)
{
    char            *hex;
    unsigned int    num;
    unsigned int    rest;
    int count;

    count = 0;
    hex = "0123456789abcdef";
    num = va_arg(arg, unsigned int);
    rest = sla_function(num, hex);
    count += write(1, &rest, 1);
    return (count);
}

unsigned int    sla_function(unsigned int nb, char * hex)
{
    unsigned int rest;

    rest = 0;
    while (nb > 16)
    {
        sla_function(nb/16, hex);
        rest = nb % 16;
        write (1, &rest[hex], 1);
    }
    return (rest);
}

/* int print_uphex(va_list arg)
{
    char *hex;

    hex = "0123456789ABCDEF";
} */