/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:47:07 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/07 21:24:40 by klino-an         ###   ########.fr       */
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
	while (s1 && s1[i])
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

/* char	*write_line(char *temp)
{
	size_t i;
	size_t j;
	char *new_str;

	i = 0;
	j = 0;
	if (!temp)
		return (NULL);
	while(temp[j] && temp[j] != '\n')
		j++;
	new_str = malloc(j + 1);
	if (!new_str)
		return (free(new_str), NULL);
	while (i < j)
	{
		new_str[i] = temp[i];
		i++;
	}
	new_str[j + 1] = '\0';
	return(new_str);    
} */


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

void	update_buffer(char *buffer)
{
	size_t i;
	size_t buffer_size;

	i = 0;
	buffer_size = ft_strlen(buffer);
	while (i < buffer_size)
	{
		if(buffer[i] != '\n')
			i++;
	}
}