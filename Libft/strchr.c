#include <string.h>
#include <stdio.h>

char *ft_strchr(const char *str, int c)
{
    size_t i = 0;
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
    int x = 'i';
     printf("%s\n", ft_strchr(str, x));
     printf("%s\n", strchr(str, x));
    
}