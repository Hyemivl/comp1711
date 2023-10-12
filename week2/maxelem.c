#include <stdio.h>

int main()
{
    const int arraysize = 5;
    int array[arraysize];
    int max = 0;
    for (int i = 0; i < arraysize; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < arraysize; i++)
    {
        if (array[i]>max)
        {
            max = array[i];
        }
    }
    printf("%d\n",max);
    
}
