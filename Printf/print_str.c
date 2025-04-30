/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:58:47 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/30 12:50:45 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    print_str(va_list arg)
{
    int count;
    const char *str;
    size_t i;

    count = 0;
    i = 0;
    str = va_arg(arg, const char *);
    while(str[i])
    {
        count +=write(1, &str[i], 1);
        i++;
    }
    return (count);
}