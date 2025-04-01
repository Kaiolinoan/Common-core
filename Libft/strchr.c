#include <string.h>
#include <stdio.h>

char *ft_strchr(const char *str, int c)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == (char)c)
            return ((char*)&str[i]);
        i++;
    }
    if((char)c == '\0')
        return ((char*)&str[i]);
    return (NULL);
}

int main()
{
    char str[] = "oloiasoda a";
    int x = 0;
     printf("%p\n", ft_strchr(str, x));
     printf("%p\n", strchr(str, x));
    
}