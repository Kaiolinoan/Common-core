/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:38:39 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/11 12:55:05 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char s1[], const char s2[], size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		while (i < n)
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/* int main()
{
	char s1[] = "ola";
	char s2[] = "olA";
	int x = 3;

	printf("%d\n", ft_strncmp(s1, s2, x));
	printf("%d\n", strncmp(s1, s2, x));
} */