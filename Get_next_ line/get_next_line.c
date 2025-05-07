/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:47:02 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/07 21:17:42 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    ssize_t chars_read;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    chars_read = 1;
    line = NULL;
    while (1)
    {
        if(buffer[0] == '\0')
            chars_read = read(fd, buffer, BUFFER_SIZE);
        if (chars_read < 0)
            return (NULL);
        else if (chars_read == 0)
            return(line);
        buffer[chars_read] = '\0';
        if(!(line = ft_strjoin(line, buffer)))
        return (NULL);
        if (ft_strchr(buffer, '\n'))
             break;
    }
    update_buffer(buffer);
    return(line);
}

int main()
{
    // int fd = open("test.txt", O_RDONLY);
    // get_next_line(fd);
    char *s1 = strdup("ola");
    char *s2 = strdup("mundo");
    char *str = ft_strjoin(s1, s2);
    printf ("%s", str);
    free(str);
    // printf("%s", get_next_line(fd));
    // close (fd);
}