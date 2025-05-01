/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:58:44 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/01 20:46:21 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_pointer(void *ptr)
{
    int count;
    unsigned long int address;

    address = (unsigned long int)ptr;
    count = 0;
    count += write(1, "0x", 2);
    count += print_hex(address, "0123456789abcdef");
    return (count);
}
