#include <stdio.h>
#include <ctype.h>

int ft_isascii(int c)
{
    if((c >= 0 && c <= 127))
        return(1);
    return (0);
}

int main()
{
    int a = 'a';
    int b = 'A';
    int c = 128;

    printf("%d\n", ft_isascii(a));
    printf("%d\n", ft_isascii(b));
    printf("%d\n", ft_isascii(c));

    printf("\n");

    printf("%d\n", isascii(a));
    printf("%d\n", isascii(b));
    printf("%d\n", isascii(c));

}