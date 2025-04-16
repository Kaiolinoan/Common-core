/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_do_mano.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:19:02 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/16 19:04:32 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_cond(const char *str, size_t start, char c)
{
	size_t	i;
	
	i = 0;
	while (str[start + i] && str[start + i] != c)
			i++;
	return i;
}

static char *split_str(char const *s, size_t start, char c)
{
	size_t	i;
	size_t	len;
	char *sub_cpy;

	i = 0;

	
	len= ft_strlen_cond(s, start, c);
	sub_cpy = malloc(sizeof(char)*(len +1));
	while (s[start + i] && i < len)
	{
		sub_cpy[i] = s[start + i];
		i++;
	}
	return sub_cpy;
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i + 1] != c)
			i++;
		if (s[i] != c && s[i + 1] == c)
		{
			count++;
			i++;
		}
		if (s[i] != c && s[i + 1] == '\0')
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**matriz;
	size_t	total_words;
	size_t i = 0;
	size_t array_i = 0;

	total_words = count_words(s, c);
	if (!s)
		return (NULL);
	matriz = (char **)malloc(total_words * sizeof(char *) + 1);
	if (!matriz)
		return (NULL);
	while (i < total_words)
	{
		while (s[array_i] && s[array_i] == c)
			array_i++;
		matriz[i] = split_str(s, array_i, c);
		i++;
		array_i += ft_strlen_cond(s, array_i, c);
	}
	matriz[i] = NULL;
	return (matriz);
}

/* int	main(void)
{
	char	str[] = "banana, uva, maca, pera";
	char	**matriz;

	matriz = ft_split(str, ',');
	printf("%s", matriz[0]);
} */

