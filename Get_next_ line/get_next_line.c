// COLOCAR O HEADER

#include "get_next_line.h"

char *get_next_line(int fd)
{
    void *buffer[1024];
    ssize_t data;
    
    data = read(fd, buffer, BUFFER_SIZE);


}

/* int main()
{
    int fd = open("test,txt", O_RDONLY);
    get_next_line(fd);
} */