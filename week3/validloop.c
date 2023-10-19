#include <stdio.h>

int main()
{
    int input;
    printf("Enter a value to be validated (Between 0-100): ");
    scanf("%d",&input);
    while (input != -1) 
    {
        if (input >= 0 && input <= 100)
        {
            printf("%d is a valid number\n",input);
        }
        else
        {
            printf("%d is not a valid number\n",input);
        }
        printf("Enter a value to be validated (Between 0-100): ");
        scanf("%d",&input);
    }
    printf("Thank you for using this program\n");
    
    
}