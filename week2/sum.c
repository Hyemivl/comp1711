#include <stdio.h>

int main()
{
    int num1;
    int num2;
    printf("Enter your first number: ");
    scanf("%d",&num1);
    printf("Enter your second number: ");
    scanf("%d",&num2);
    printf("The sum of %d + %d is %d\n",num1,num2,num1+num2);
    return 0;
}