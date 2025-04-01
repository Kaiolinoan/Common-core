#include <stdio.h>
#include <string.h>

char *ft_strnstr(char str[], char to_find[], size_t n)
{
    size_t i = 0;
    size_t j;
    
    if (to_find[i] == '\0')
    return((char*)str);
    
    while (str[i] &&  i < n)
    {
        j = 0;
        while(str[i + j] && (str[i + j] == to_find[j]) && (i + j < n))
        {
            if(to_find[j + 1] == '\0')
                return((char*)&str[i]);
            j++;
        }
        i++;
        
    }
    return (NULL);
}
 
int main()
{
    char *str = "ola";
    char *str2 = "la";
    size_t i = 3;
    printf("%s\n",ft_strnstr(str, str2, i));
} 