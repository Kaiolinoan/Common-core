/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:37:17 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/15 18:34:27 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*sub;

	if (*s == '\0' || start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	count = 0;
	while (count < len && s[start + count])
		count++;
	sub = (char *)malloc((count + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], count + 1);
	return (sub);
}

/* int main()
{
   // Teste 1: Substring comum
	char *s1 = ft_substr("eu vou copiar esta string", 8, 6);
	printf("Teste 1: \"%s\"\n", s1); // esperado: "copiar"
	free(s1);

	// Teste 2: Substring no começo
	char *s2 = ft_substr("inicio", 0, 3);
	printf("Teste 2: \"%s\"\n", s2); // esperado: "ini"
	free(s2);

	// Teste 3: Substring maior que a string restante
	char *s3 = ft_substr("final", 3, 10);
	printf("Teste 3: \"%s\"\n", s3); // esperado: "al"
	free(s3);

	// Teste 4: Começa no fim da string
	char *s4 = ft_substr("abc", 3, 2);
	printf("Teste 4: \"%s\"\n", s4); // esperado: ""
	free(s4);

	char *s5 = ft_substr("1", 42, 42000000);
	printf("Teste 5: \"%s\"\n", s5);
	free(s5);

	// Teste 6: Len = 0 (retorna string vazia)
	char *s6 = ft_substr("abcde", 2, 0);
	printf("Teste 6: \"%s\"\n", s6); // esperado: ""
	free(s6);

	// Teste 7: String vazia como entrada
	char *s7 = ft_substr("", 0, 5);
	printf("Teste 7: \"%s\"\n", s7); // esperado: ""
	free(s7);
} */