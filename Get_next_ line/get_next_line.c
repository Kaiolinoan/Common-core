/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:47:02 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/06 16:00:37 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char *get_next_line(int fd)
{
    static char *buffer[BUFFER_SIZE + 1];
    char *string;
    ssize_t data;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    string = NULL; 
    data = read(fd, buffer, BUFFER_SIZE);

    return(string);
} */

int main()
{
    // int fd = open("test,txt", O_RDONLY);
    // get_next_line(fd);
    char *s1 = "ola, ";
    char *s2 = "mundo";
    printf ("%s", ft_strjoin(s1, s2));
}