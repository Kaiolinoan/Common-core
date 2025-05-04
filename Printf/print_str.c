/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:58:47 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/01 11:07:39 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    print_str(const char *str)
{
    int count;
    size_t i;

    count = 0;
    i = 0;
    if(!str)
    {
        count+= write(1,"(null)", 6);
        return (-1);
    }
    while(str[i])
    {
        count +=write(1, &str[i], 1);
        i++;
    }
    return (count);
}