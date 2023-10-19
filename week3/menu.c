#include <stdio.h>
#include <stdbool.h>

int main()
{
    int option;
    do
    {
        printf("Enter your option (1-5): ");
        scanf("%d",&option);

    
    switch (option)
    {
    case 1:
        printf("Option 1 has been chosen.\n");
        break;
    case 2:
        printf("Option 2 has been chosen.\n");
        break;    
    case 3:
        printf("Option 3 has been chosen.\n");
        break;
    case 4:
        printf("Option 4 has been chosen.\n");
        break;
    case 5:
        printf("Option 5 has been chosen.\n");
        break;    
    default:
        printf("This is an invalid option\n");
        break;
    }
    } while (option < 1 || option > 5);
    return 0;
}