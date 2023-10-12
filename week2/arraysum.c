#include <stdio.h>

int main()
{
    int array[5];
    int sum = 0;
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("Enter a number: ");
        scanf("%d", &array[i]);
    }
    
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        sum += array[i];
        printf("%d\n",sum);
    }
    printf("The sum of these numbers is %d\n", sum);
    
}