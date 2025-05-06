/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:47:16 by klino-an          #+#    #+#             */
/*   Updated: 2025/05/06 13:33:53 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
# include <fcntl.h>

# define BUFFER_SIZE 1024

char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif