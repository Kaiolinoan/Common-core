#include <stdio.h>
#include <string.h>

static size_t ft_strlen(const char *str) //A funcao tem que ser do tipo int ou size_t??
{
    size_t i = 0;
    while(str[i])
        i++;
    return(i);
}

size_t ft_strlcpy(char dst[], const char *restrict src, size_t size)
{
    size_t i = 0;
    size_t size_src = ft_strlen(src);

    if (size == 0)
        return(size_src);
    while(src[i] && i < size - 1 )
    {
        dst[i] = src[i];
        i++;
    }
 

    dst[i] = '\0';
    return (size_src);
}

int main ()
{
    char src[] = "ola tudo bem";
    char dst[] = "";
    size_t i = 12;

    printf("%zu\n", ft_strlcpy(dst, src, i));
    printf("%zu\n", strlcpy(dst, src, i));

    ft_strlcpy(dst, src, i);
    strlcpy(dst, src, i);

    printf("%s\n", dst);
    printf("%s\n", dst);
}
