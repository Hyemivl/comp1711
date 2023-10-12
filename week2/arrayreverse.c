#include <stdio.h>

int main()
{
    int array[5];
    int arrayrev[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&array[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        arrayrev[i] = array[4-i];
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",arrayrev[i]);
    }
    
    
}