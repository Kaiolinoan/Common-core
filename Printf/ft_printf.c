/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:15:44 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/01 20:26:21 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char i, va_list args)
{
	int	count;

	count = 0;
	if (i == 'c')
		count += print_char(va_arg(args, int));
	else if (i == 's')
		count += print_str(va_arg(args, const char*));
	else if (i == 'p')
		count += print_pointer(va_arg(args, void*));
	else if (i == 'd')
		count += print_numbers(va_arg(args, int));
	else if (i == 'i')
		count += print_numbers(va_arg(args, int));
	else if (i == 'u')
	    count += print_unsigned(va_arg(args, unsigned int));
	else if (i == 'x')
		count += print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (i == 'X')
		count += print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (i == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i++] == '%')
			count += check_type(str[i++], args); //checkar por erros depois
		count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	// char c = 'A';
	// char *str = "isto e uma string";
	unsigned int nb = 42;
	// ft_printf("ola\n");
	//    printf("ola\n");
	// ft_printf("%s\n",str);
	// printf("%s\n",str);
	// ft_printf("%c %c\n",c, 'a');
	// printf("%c %c\n",c, 'a');
	// printf("%c\n",c);
	// ft_printf("%x\n", nb);
	// printf("%x\n", nb);
    ft_printf("%p\n", &nb);
	   printf("%p\n", &nb);
    // ft_printf("%%\n");
	//    printf("%%\n");
}