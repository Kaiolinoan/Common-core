#include <stdio.h>
#include <ctype.h>

int ft_tolower(int c)
{
    if((c >= 65 && c <= 90))
        return(c + 32);
    return (c);
}

int main()
{
    int a = 'a';
    int b = 'A';
    int c = '\t';

    printf("%d\n", ft_tolower(a));
    printf("%d\n", ft_tolower(b));
    printf("%d\n", ft_tolower(c));

    printf("\n");

    printf("%d\n", tolower(a));
    printf("%d\n", tolower(b));
    printf("%d\n", tolower(c));

}