#include <string.h>
#include <stdio.h>

static int ft_strlen(const char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}

char *ft_strrchr(const char *str, int c)
{
   int i = ft_strlen(str);

   while (str[i] >= 0)
   {
        if(str[i] == (char)c)
            return((char*)&str[i]);
        i--;
   }
   return (NULL);
}

int main()
{
    char str[] = "oloiasoda a";
    int x = 'o';
     printf("%s\n", ft_strrchr(str, x));
     printf("%s\n", strrchr(str, x));
    
}


