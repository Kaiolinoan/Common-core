#include <stdio.h>
#include <ctype.h>

int ft_isprint(int c)
{
    if((c >= 32 && c <= 126))
        return(16384);
    return (0);
}

int main()
{
    int a = 'a';
    int b = 'A';
    int c = '\n';

    printf("%d\n", ft_isprint(a));
    printf("%d\n", ft_isprint(b));
    printf("%d\n", ft_isprint(c));

    printf("\n");

    printf("%d\n", isprint(a));
    printf("%d\n", isprint(b));
    printf("%d\n", isprint(c));

}