#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    setlocale(0, "");
    printf("¬ведите год: ");
    scanf("%i",&x);
    if ((x%4==0&&x%100!=0)||(x%400==0))
        printf("366");
    else
        printf("365");
    return 0;
}
