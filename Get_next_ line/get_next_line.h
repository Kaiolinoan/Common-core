//COLOCAR O HEADER

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
# include <fcntl.h>

# define BUFFER_SIZE 1024

char *get_next_line(int fd);



#endif