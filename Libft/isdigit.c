#include <stdio.h>
#include <ctype.h>

int ft_digit(int c)
{
    if((c >= '0' && c <= '9'))
        return(2048);
    return (0);
}

int main()
{
    int a = 'a';
    int b = 'A';
    int c = '9';

    printf("%d\n", ft_digit(a));
    printf("%d\n", ft_digit(b));
    printf("%d\n", ft_digit(c));

    printf("\n");

    printf("%d\n", isdigit(a));
    printf("%d\n", isdigit(b));
    printf("%d\n", isdigit(c));

}