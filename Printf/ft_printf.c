/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:15:44 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/29 18:55:13 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void check_type(int i, va_list args)
{
    if(i == 'c')
        print_char(args);
    else if(i == 's')
        print_str(args);
    else if(i == 'p')
        print_pointer();
    else if(i == 'd')
        print_decimal();
    else if(i == 'i')
        print_integer();
    else if(i == 'u')
        print_unsigned();
    else if(i == 'x')
        print_lowhex();
    else if(i == 'X')
        print_uphex();
}

int ft_printf(const char *str, ...)
{
    va_list args;
    va_list copy;
    size_t i;

    if(!str)
        return (-1);
    va_start(args, str);
    va_copy(copy, args);
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '%')
        {
            i++;
            check_type(i, va_arg(args, char *));
        }
        i++;
    }
    va_end(copy);
    va_end(args);
    return(1); //arrumar isto
}

int main()
{
    char c = 'A';
    ft_printf("%c",c);
    printf("%c",c);
}