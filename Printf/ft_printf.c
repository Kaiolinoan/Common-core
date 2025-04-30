/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:15:44 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/30 13:48:15 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_type(char i, va_list args)
{
    int count;

    count = 0;
    if(i == 'c')
        count+=print_char(args);
    else if(i == 's')
        count+=print_str(args);
    // else if(i == 'p')
        // print_pointer();
    // else if(i == 'd')
    //     print_decimal();
    // else if(i == 'i')
    //     print_integer();
    // else if(i == 'u')
    //     print_unsigned();
    else if(i == 'x')
        count+=print_lowhex(args);
    // else if(i == 'X')
    //     print_uphex();
    return (count);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int     count;
    size_t  i;

    if(!str)
        return (-1);
    i = 0;
    count = 0;
    va_start(args, str);
    while(str[i])
    {
        if(str[i++] == '%')
            count+=check_type(str[i++], args);
        count+=write(1, &str[i], 1);
        i++;
    }
    va_end(args);
    return(count);
}

int main()
{
    // char c = 'A';
    // char *str = "isto e uma string";
    int nb = 15;
    // ft_printf("ola\n");
    //    printf("ola\n");
    // ft_printf("%s\n",str);
    // printf("%s\n",str);
    // ft_printf("%c %c\n",c, 'a');
    // printf("%c %c\n",c, 'a');
    // printf("%c\n",c);
    ft_printf("%x\n",nb);
       printf("%x\n",nb);
}