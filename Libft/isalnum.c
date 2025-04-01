#include <stdio.h>
#include <ctype.h>

int ft_isalnum(int c)
{
    if(!((c >= '0' && c <= '9')|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
        return(0);
    return (8);
}

int main()
{
    int a = 'a';
    int b = 'A';
    int c = '*';

    printf("%d\n", ft_isalnum(a));
    printf("%d\n", ft_isalnum(b));
    printf("%d\n", ft_isalnum(c));

    printf("\n");

    printf("%d\n", isalnum(a));
    printf("%d\n", isalnum(b));
    printf("%d\n", isalnum(c));

}
