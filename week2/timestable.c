#include <stdio.h>

int main()
{
    for(int a = 1; a <= 12; a++)
    {
        for(int b = 1; b <= 12; b++)
        {
            printf("%d * %d = %d\n",a,b,a*b);
        }
    }
    return 0;
}