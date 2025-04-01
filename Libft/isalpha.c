#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return(1024);
    return (0);
}

int main()
{
    int a = 'a';
    int b = 'A';
    int c = '9';

    printf("%d\n", ft_isalpha(a));
    printf("%d\n", ft_isalpha(b));
    printf("%d\n", ft_isalpha(c));

    printf("%d\n", isalpha(a));
    printf("%d\n", isalpha(b));
    printf("%d\n", isalpha(c));

}