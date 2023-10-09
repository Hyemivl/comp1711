#include <stdio.h>

int main()
{
    // alloting 15 characters to the array name
    char name[15];

    // Tell user to give an input
    printf("Hello, please enter your name: ");

    // Taking user input and storing in the array name
    scanf("%s", name);

    // printing users input
    printf("Your name is %s\n", name);

    return 0;
}