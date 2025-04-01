#include <stdio.h>
#include <ctype.h>

int ft_toupper(int c)
{
    if((c >= 97 && c <= 122))
        return(c - 32);
    return (c);
}

int main()
{
    int a = 'a';
    int b = 'A';
    int c = '\t';

    printf("%d\n", ft_toupper(a));
    printf("%d\n", ft_toupper(b));
    printf("%d\n", ft_toupper(c));

    printf("\n");

    printf("%d\n", toupper(a));
    printf("%d\n", toupper(b));
    printf("%d\n", toupper(c));

}