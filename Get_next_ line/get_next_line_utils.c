/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:47:07 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/08 19:07:28 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str) 
		return (0);
	while (str[i])
	{
		if(str[i++] == '\n')
			break;
	}
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (!s1 && s1[i])
	{
		str[i] = s1[i];
		i++; 
	}
	j = 0;
	while (s2[j])
	{	
		str[i++] = s2[j];
		if (s2[j++] == '\n')
			break;
	}
	str[i] = '\0';
	free (s1);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

void	update_buffer(char *buffer, size_t j)
{
	size_t i;
	size_t buffer_size;
	char *temp;

	i = 0;
	temp = NULL;
	buffer_size = ft_strlen(buffer);
	while (buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		while (i < buffer_size)
			temp[j++] = buffer[i++];
	}
	i = 0;
	while (i < buffer_size)
		buffer[i++] = '\0';
	i = 0;
	while (temp[i])
	{
		buffer[i] = temp[i];
		i++;
	}
}

