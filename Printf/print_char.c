/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:58:37 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/29 18:34:32 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_char(va_list arg)
{
    int c;
    unsigned char uc;

    c = arg;
    uc = (unsigned char)c;
    write(1, &uc, 1);
}