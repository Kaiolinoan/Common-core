/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:58:39 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/01 20:46:21 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_hex(unsigned long nb, const char *hex)
{
    int count;

    count = 0;
    if (nb >= 16)
        print_hex(nb / 16, hex); //count aqui??
    count+=write(1, &hex[nb % 16], 1);
    return (count);
}

