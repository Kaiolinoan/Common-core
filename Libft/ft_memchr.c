//#include "libft.h"
#include <string.h>
#include <stdio.h>


void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *s_pointer;
    unsigned char chr;
    size_t i;

    s_pointer = (unsigned char *)s;
    chr = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        if(s_pointer[i] == chr)
            return ((unsigned char *)&s_pointer[i]);
        i++;
    }
    return (NULL);
}

/* int main()
{
    char str[] = "eu vou procurar uma letra nessa string";

    printf("%s", ft_memchr(str, 'v', strlen(str)));
} */
