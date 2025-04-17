/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:12:19 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/16 14:57:49 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_nb(int n)
{
	size_t	count;
	int		nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	count++;
	return (count);
}

static char	*put_in_string(int n, char *str, size_t counter)
{
	size_t	counter2;

	counter2 = counter;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	else if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--counter] = (n % 10) + 48;
		n /= 10;
	}
	str[counter2] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	counter;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	counter = count_nb(n);
	str = (char *)malloc((counter + 1) * sizeof(char));
	if (!str)
		return (NULL);
	put_in_string(n, str, counter);
	return (str);
}
/* int main()
{
	printf("%s", ft_itoa(100));
} */