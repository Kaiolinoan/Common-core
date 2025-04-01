#include <string.h>
#include <stdio.h>
unsigned long ft_strlen(const char *str) //A funcao tem que ser do tipo int ou size_t??
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}

int main()
{

    printf("%d\n" ,ft_strlen("ola54"));
    printf("%d\n", strlen("ola47"));

}