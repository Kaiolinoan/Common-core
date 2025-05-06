/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:47:07 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/06 17:52:44 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++; 
    }
    j = 0;
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    // free(s1);
	return (str);
}

char *read_line(char *buffer, char *string)
{
    size_t i;

    i = 0;
    if(buffer[0] == '\0')
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        string = ft_strjoin(string, buffer);
    return(string);         

}

