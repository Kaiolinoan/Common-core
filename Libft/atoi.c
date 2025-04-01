#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str)
{
    int nb = 0;
    int sign = 1;
    int i = 0;

     while (str[i] >= 9 && str[i] <= 13)
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign = -sign;
        i++;
    }
    while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
    {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    return (nb*sign);
}

int main()
{
    char a[] = "45a6746";
    char b[]= "--87a2";
    char c[]= "-485s7";

    printf("%d\n", ft_atoi(a));
    printf("%d\n", ft_atoi(b));
    printf("%d\n", ft_atoi(c));

    printf("\n");

    printf("%d\n", atoi(a));
    printf("%d\n", atoi(b));
    printf("%d\n", atoi(c));
}