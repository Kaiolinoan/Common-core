/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:58:37 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/01 17:40:31 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    print_char(int c)
{
    int             count;
    unsigned char   uc;

    uc = (unsigned char)c;
    count = 0;
    count += write(1, &uc, 1);
    return (count);
}